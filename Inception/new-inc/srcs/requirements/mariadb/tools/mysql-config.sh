# #!/bin/bash

set -e

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

log() { echo -e "${BLUE}[MYSQL] $1${NC}"; }
error() { echo -e "${RED}[ERROR] $1${NC}" >&2; }
success() { echo -e "${GREEN}[SUCCESS] $1${NC}"; }

SECRETS_DIR="$(cd "$(dirname "$0")/../../../../secrets" && pwd)"

check_container() {
    if ! docker ps | grep -q mariadb; then
        error "MariaDB container not running"
        exit 1
    fi
}

connect() {
    check_container
    DB_ROOT_PASSWORD=$(cat "$SECRETS_DIR/db_root_password.txt")
    docker exec -it mariadb mysql -u root -p"$DB_ROOT_PASSWORD"
}

verify() {
    check_container
    if docker exec mariadb mysqladmin ping --silent; then
        success "MariaDB running"
    else
        error "MariaDB not responding"
    fi
}

stats() {
    check_container
    docker exec mariadb mysql -u root -p"$(cat "$SECRETS_DIR/db_root_password.txt")" -e "SHOW DATABASES;"
}

case "${1:-help}" in
    "connect") connect ;;
    "verify") verify ;;
    "stats") stats ;;
    *) echo "Usage: $0 {connect|verify|stats}" ;;
esac
