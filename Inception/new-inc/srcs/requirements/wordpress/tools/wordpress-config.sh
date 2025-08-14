#!/bin/bash

set -e

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

log() {
    echo -e "${BLUE}[$(date +'%Y-%m-%d %H:%M:%S')] $1${NC}"
}

error() {
    echo -e "${RED}[ERROR] $1${NC}" >&2
}

success() {
    echo -e "${GREEN}[SUCCESS] $1${NC}"
}

warning() {
    echo -e "${YELLOW}[WARNING] $1${NC}"
}

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../../../../" && pwd)"
SECRETS_DIR="$PROJECT_ROOT/secrets"
WORDPRESS_DIR="/home/nporras-/data/wordpress"
BACKUP_DIR="$PROJECT_ROOT/backups/wordpress"

check_container() {
    if ! docker ps | grep -q wordpress; then
        error "WordPress container is not running"
        log "Run 'make up' from $PROJECT_ROOT to start containers"
        exit 1
    fi
}

check_database() {
    if ! docker exec wordpress nc -z mariadb 3306; then
        error "Cannot connect to MariaDB database"
        exit 1
    fi
}

install_wordpress() {
    log "Installing WordPress..."
    
    check_container
    check_database
    
    if [ ! -f "$SECRETS_DIR/credentials.txt" ]; then
        error "Credentials file not found"
        exit 1
    fi
    
    source "$SECRETS_DIR/credentials.txt"
    
    if docker exec wordpress wp core is-installed --path=/var/www/html --allow-root 2>/dev/null; then
        warning "WordPress is already installed"
        return 0
    fi
    
    if ! docker exec wordpress which wp &>/dev/null; then
        log "Installing WP-CLI..."
        docker exec wordpress curl -O https://raw.githubusercontent.com/wp-cli/wp-cli/v2.8.1/phar/wp-cli.phar
        docker exec wordpress chmod +x wp-cli.phar
        docker exec wordpress mv wp-cli.phar /usr/local/bin/wp
    fi
    
    # Ensure WordPress is downloaded
    if ! docker exec wordpress test -f /var/www/html/wp-config-sample.php; then
        log "WordPress not found, downloading..."
        docker exec wordpress wp core download --path=/var/www/html --allow-root
    fi
    
    log "WP exec core"
    log "ADMIN USER $WORDPRESS_ADMIN_USER"
    log "ADMIN PASSWORD $WORDPRESS_ADMIN_PASSWORD"
    log "ADMIN EMAIL $WORDPRESS_ADMIN_EMAIL"
    docker exec wordpress wp core install \
        --path=/var/www/html \
        --url="https://nporras-.42.fr" \
        --title="Inception WordPress" \
        --admin_user="$WORDPRESS_ADMIN_USER" \
        --admin_password="$WORDPRESS_ADMIN_PASSWORD" \
        --admin_email="$WORDPRESS_ADMIN_EMAIL" \
        --allow-root
    
    log "WP user create"
    docker exec wordpress wp user create \
        --path=/var/www/html \
        "$WORDPRESS_USER" \
        "$WORDPRESS_USER_EMAIL" \
        --user_pass="$WORDPRESS_USER_PASSWORD" \
        --role=author \
        --allow-root
    
    success "WordPress installed successfully"
    
    echo
    log "Access information:"
    echo "URL: https://nporras-.42.fr"
    echo "Admin: $WORDPRESS_ADMIN_USER / $WORDPRESS_ADMIN_PASSWORD"
    echo "User: $WORDPRESS_USER / $WORDPRESS_USER_PASSWORD"
}

backup_wordpress() {
    log "Creating WordPress backup..."
    
    check_container
    
    mkdir -p "$BACKUP_DIR"
    BACKUP_DATE=$(date +%Y%m%d_%H%M%S)
    
    log "Creating file backup..."
    docker exec wordpress tar -czf "/tmp/wordpress_files_$BACKUP_DATE.tar.gz" -C /var/www/html .
    docker cp "wordpress:/tmp/wordpress_files_$BACKUP_DATE.tar.gz" "$BACKUP_DIR/"
    docker exec wordpress rm "/tmp/wordpress_files_$BACKUP_DATE.tar.gz"
    
    log "Creating database backup..."
    docker exec wordpress wp db export "/tmp/wordpress_db_$BACKUP_DATE.sql" --allow-root
    docker cp "wordpress:/tmp/wordpress_db_$BACKUP_DATE.sql" "$BACKUP_DIR/"
    docker exec wordpress rm "/tmp/wordpress_db_$BACKUP_DATE.sql"
    
    gzip "$BACKUP_DIR/wordpress_db_$BACKUP_DATE.sql"
    
    success "Backup completed:"
    success "Files: $BACKUP_DIR/wordpress_files_$BACKUP_DATE.tar.gz"
    success "Database: $BACKUP_DIR/wordpress_db_$BACKUP_DATE.sql.gz"
}

restore_wordpress() {
    log "Restoring WordPress backup..."
    
    check_container
    
    if [ ! -d "$BACKUP_DIR" ] || [ -z "$(ls -A $BACKUP_DIR 2>/dev/null)" ]; then
        error "No backups found in $BACKUP_DIR"
        exit 1
    fi
    
    echo "Available backups:"
    ls -la "$BACKUP_DIR"
    
    read -p "Enter backup date to restore (YYYYMMDD_HHMMSS): " backup_date
    
    if [ ! -f "$BACKUP_DIR/wordpress_files_$backup_date.tar.gz" ] || [ ! -f "$BACKUP_DIR/wordpress_db_$backup_date.sql.gz" ]; then
        error "Backup files not found for specified date"
        exit 1
    fi
    
    warning "This action will overwrite all current WordPress files and data!"
    read -p "Are you sure you want to continue? (yes/no): " confirm
    
    if [ "$confirm" != "yes" ]; then
        log "Restoration cancelled"
        exit 0
    fi
    
    log "Restoring WordPress files..."
    docker cp "$BACKUP_DIR/wordpress_files_$backup_date.tar.gz" wordpress:/tmp/
    docker exec wordpress sh -c "cd /var/www/html && rm -rf * && tar -xzf /tmp/wordpress_files_$backup_date.tar.gz"
    docker exec wordpress rm "/tmp/wordpress_files_$backup_date.tar.gz"
    docker exec wordpress chown -R www-data:www-data /var/www/html
    
    log "Restoring database..."
    gunzip -c "$BACKUP_DIR/wordpress_db_$backup_date.sql.gz" > "/tmp/restore_db.sql"
    docker cp "/tmp/restore_db.sql" wordpress:/tmp/
    docker exec wordpress wp db import /tmp/restore_db.sql --allow-root
    docker exec wordpress rm /tmp/restore_db.sql
    rm "/tmp/restore_db.sql"
    
    success "WordPress restored successfully"
}

update_wordpress() {
    log "Updating WordPress..."
    
    check_container
    
    log "Creating automatic backup before update..."
    backup_wordpress
    
    docker exec wordpress wp core update --allow-root
    docker exec wordpress wp core update-db --allow-root
    
    docker exec wordpress wp plugin update --all --allow-root
    
    docker exec wordpress wp theme update --all --allow-root
    
    success "WordPress updated successfully"
}

install_plugins() {
    log "Installing useful plugins..."
    
    check_container
    
    plugins=(
        "wordpress-seo"
        "akismet"
        "wordfence"
        "wp-super-cache"
        "contact-form-7"
        "updraftplus"
    )
    
    for plugin in "${plugins[@]}"; do
        log "Installing plugin: $plugin"
        if docker exec wordpress wp plugin install "$plugin" --allow-root; then
            docker exec wordpress wp plugin activate "$plugin" --allow-root
            success "Plugin $plugin installed and activated"
        else
            warning "Could not install plugin $plugin"
        fi
    done
}

optimize_wordpress() {
    log "Optimizing WordPress..."
    
    check_container
    
    log "Cleaning database..."
    docker exec wordpress wp db optimize --allow-root
    
    log "Cleaning cache..."
    docker exec wordpress wp cache flush --allow-root 2>/dev/null || log "No active cache plugin"
    
    log "Removing old revisions..."
    docker exec wordpress wp post delete $(docker exec wordpress wp post list --post_type=revision --format=ids --allow-root) --allow-root 2>/dev/null || log "No revisions to remove"
    
    docker exec wordpress wp db query "OPTIMIZE TABLE $(docker exec wordpress wp db tables --format=csv --allow-root | tail -n +2 | tr '\n' ',' | sed 's/,$//')" --allow-root
    
    success "WordPress optimized"
}

show_info() {
    log "WordPress information..."
    
    check_container
    
    echo "=== GENERAL INFORMATION ==="
    docker exec wordpress wp core version --allow-root 2>/dev/null || echo "WP-CLI not available"
    
    echo
    echo "=== USERS ==="
    docker exec wordpress wp user list --allow-root 2>/dev/null || echo "Cannot get user list"
    
    echo
    echo "=== PLUGINS ==="
    docker exec wordpress wp plugin list --allow-root 2>/dev/null || echo "Cannot get plugin list"
    
    echo
    echo "=== THEMES ==="
    docker exec wordpress wp theme list --allow-root 2>/dev/null || echo "Cannot get theme list"
    
    echo
    echo "=== DATABASE STATUS ==="
    docker exec wordpress wp db check --allow-root 2>/dev/null || echo "Cannot verify database"
    
    echo
    echo "=== CONFIGURATION ==="
    if docker exec wordpress test -f /var/www/html/wp-config.php; then
        success "wp-config.php file exists"
        docker exec wordpress grep -E "(DB_NAME|DB_HOST|DB_USER)" /var/www/html/wp-config.php | head -3
    else
        error "wp-config.php file not found"
    fi
}

verify_config() {
    log "Verifying WordPress configuration..."
    
    check_container
    check_database
    
    if docker exec wordpress test -f /var/www/html/wp-config.php; then
        success "wp-config.php: OK"
    else
        error "wp-config.php: NOT FOUND"
    fi
    
    if docker exec wordpress test -f /var/www/html/index.php; then
        success "index.php: OK"
    else
        error "index.php: NOT FOUND"
    fi
    
    log "Verifying file permissions..."
    docker exec wordpress ls -la /var/www/html/ | head -5
    
    if docker exec wordpress wp db check --allow-root 2>/dev/null; then
        success "Database connection: OK"
    else
        error "Database connection: FAILED"
    fi
    
    if docker exec wordpress pgrep php-fpm7.4; then
        success "PHP-FPM: OK"
    else
        error "PHP-FPM: NOT RUNNING"
    fi
}

fix_permissions() {
    log "Fixing WordPress file permissions..."
    
    check_container
    
    log "Setting ownership to www-data:www-data..."
    docker exec wordpress chown -R www-data:www-data /var/www/html
    
    log "Setting directory permissions to 755..."
    docker exec wordpress find /var/www/html -type d -exec chmod 755 {} \;
    
    log "Setting file permissions to 644..."
    docker exec wordpress find /var/www/html -type f -exec chmod 644 {} \;
    
    log "Setting wp-content permissions to 775..."
    docker exec wordpress chmod -R 775 /var/www/html/wp-content
    
    log "Setting wp-config.php permissions to 600..."
    docker exec wordpress chmod 600 /var/www/html/wp-config.php
    
    success "File permissions fixed successfully"
    log "Current wp-content permissions:"
    docker exec wordpress ls -la /var/www/html/wp-content/
}

verify_passwords() {
    log "Verifying WordPress passwords..."
    
    check_container
    
    if [ ! -f "$SECRETS_DIR/credentials.txt" ]; then
        error "Credentials file not found: $SECRETS_DIR/credentials.txt"
        echo "Please create the file with the following format:"
        echo "WORDPRESS_ADMIN_USER=admin"
        echo "WORDPRESS_ADMIN_PASSWORD=your_admin_password"
        echo "WORDPRESS_ADMIN_EMAIL=noe@porras.me"
        echo "WORDPRESS_USER=user"
        echo "WORDPRESS_USER_PASSWORD=your_user_password"
        echo "WORDPRESS_USER_EMAIL=nporras-@student.42malaga.com"
        exit 1
    fi
    
    source "$SECRETS_DIR/credentials.txt"
    
    if docker exec wordpress wp user get "$WORDPRESS_ADMIN_USER" --allow-root &>/dev/null; then
        success "Admin user '$WORDPRESS_ADMIN_USER' exists"
    else
        warning "Admin user '$WORDPRESS_ADMIN_USER' not found"
        log "You may need to run the install command first"
    fi
    
    if docker exec wordpress wp user get "$WORDPRESS_USER" --allow-root &>/dev/null; then
        success "User '$WORDPRESS_USER' exists"
    else
        warning "User '$WORDPRESS_USER' not found"
        log "You may need to run the install command first"
    fi
    
    log "Password verification completed. To change passwords, update the credentials file manually."
}

show_help() {
    echo "Usage: $0 [OPTION]"
    echo
    echo "Available options:"
    echo "  install     - Install WordPress with WP-CLI"
    echo "  backup      - Create complete WordPress backup"
    echo "  restore     - Restore WordPress backup"
    echo "  update      - Update WordPress, plugins and themes"
    echo "  plugins     - Install useful plugins"
    echo "  optimize    - Optimize WordPress and database"
    echo "  info        - Show WordPress information"
    echo "  verify      - Verify WordPress configuration"
    echo "  permissions - Fix WordPress file permissions"
    echo "  passwords   - Verify user passwords"
    echo "  help        - Show this help"
}

main() {
    case "${1:-help}" in
        "install")
            install_wordpress
            ;;
        "backup")
            backup_wordpress
            ;;
        "restore")
            restore_wordpress
            ;;
        "update")
            update_wordpress
            ;;
        "plugins")
            install_plugins
            ;;
        "optimize")
            optimize_wordpress
            ;;
        "info")
            show_info
            ;;
        "verify")
            verify_config
            ;;
        "permissions")
            fix_permissions
            ;;
        "passwords")
            verify_passwords
            ;;
        "help"|*)
            show_help
            ;;
    esac
}

main "$@"
