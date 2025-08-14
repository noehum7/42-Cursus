#!/bin/bash

set -e

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

log() {
    echo -e "${BLUE}[INIT] $1${NC}"
}

success() {
    echo -e "${GREEN}[SUCCESS] $1${NC}"
}

warning() {
    echo -e "${YELLOW}[WARNING] $1${NC}"
}

PROJECT_DIR="$(cd "$(dirname "$0")/../.." && pwd)"
SECRETS_DIR="$PROJECT_DIR/secrets"

generate_password() {
    local length=${1:-16}
    openssl rand -base64 $length | tr -d "=+/" | cut -c1-$length
}

init_secrets() {
    log "Initializing secret files..."
    
    mkdir -p "$SECRETS_DIR"
    
    if [ ! -f "$SECRETS_DIR/db_password.txt" ]; then
        DB_PASSWORD=$(generate_password 20)
        echo "$DB_PASSWORD" > "$SECRETS_DIR/db_password.txt"
        chmod 600 "$SECRETS_DIR/db_password.txt"
        success "Created db_password.txt"
    else
        warning "db_password.txt already exists, skipping..."
    fi
    
    if [ ! -f "$SECRETS_DIR/db_root_password.txt" ]; then
        DB_ROOT_PASSWORD=$(generate_password 20)
        echo "$DB_ROOT_PASSWORD" > "$SECRETS_DIR/db_root_password.txt"
        chmod 600 "$SECRETS_DIR/db_root_password.txt"
        success "Created db_root_password.txt"
    else
        warning "db_root_password.txt already exists, skipping..."
    fi
    
    if [ ! -f "$SECRETS_DIR/credentials.txt" ]; then
        ADMIN_PASSWORD=$(generate_password 16)
        USER_PASSWORD=$(generate_password 16)
        
        cat > "$SECRETS_DIR/credentials.txt" << EOF
WORDPRESS_ADMIN_USER=user42
WORDPRESS_ADMIN_PASSWORD=$ADMIN_PASSWORD
WORDPRESS_ADMIN_EMAIL=noe@porras.me
WORDPRESS_USER=nporras-
WORDPRESS_USER_PASSWORD=$USER_PASSWORD
WORDPRESS_USER_EMAIL=nporras-@student.42malaga.com
EOF
        chmod 600 "$SECRETS_DIR/credentials.txt"
        success "Created credentials.txt"
    else
        warning "credentials.txt already exists, skipping..."
    fi
    
    if [ ! -f "$SECRETS_DIR/wp_salts" ]; then
        log "Generating WordPress security salts..."
        
        cat > "$SECRETS_DIR/wp_salts" << EOF
AUTH_KEY='$(generate_password 64)'
SECURE_AUTH_KEY='$(generate_password 64)'
LOGGED_IN_KEY='$(generate_password 64)'
NONCE_KEY='$(generate_password 64)'
AUTH_SALT='$(generate_password 64)'
SECURE_AUTH_SALT='$(generate_password 64)'
LOGGED_IN_SALT='$(generate_password 64)'
NONCE_SALT='$(generate_password 64)'
EOF
        chmod 600 "$SECRETS_DIR/wp_salts"
        success "Created wp_salts"
    else
        warning "wp_salts already exists, skipping..."
    fi
}

init_env_file() {
    log "Initializing environment file..."
    
    ENV_FILE="$PROJECT_DIR/.env"
    
    if [ ! -f "$ENV_FILE" ]; then
        cat > "$ENV_FILE" << EOF
MYSQL_DATABASE=wordpress_db
MYSQL_USER=wordpress_user
WORDPRESS_DB_HOST=mariadb
WORDPRESS_DB_NAME=wordpress_db
WORDPRESS_DB_USER=wordpress_user
DOMAIN_NAME=nporras-.42.fr
DATA_DIR=/home/nporras-/data
EOF
        success "Created .env file"
    else
        warning ".env file already exists, skipping..."
    fi
}

main() {
    log "Initializing Inception project configuration..."
    
    init_secrets
    init_env_file
    
    success "Configuration initialization completed!"
    log "Next steps:"
    echo "  1. Run: make build"
    echo "  2. Run: make up"
}

main "$@"
