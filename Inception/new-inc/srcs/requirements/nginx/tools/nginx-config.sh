#!/bin/bash

set -e

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

log() { echo -e "${BLUE}[NGINX] $1${NC}"; }
error() { echo -e "${RED}[ERROR] $1${NC}" >&2; }
success() { echo -e "${GREEN}[SUCCESS] $1${NC}"; }

check_container() {
    if ! docker ps | grep -q nginx; then
        error "Nginx container not running"
        exit 1
    fi
}

test() {
    check_container
    if docker exec nginx nginx -t; then
        success "Configuration valid"
    else
        error "Configuration invalid"
        exit 1
    fi
}

ssl() {
    check_container
    if docker exec nginx test -f /etc/nginx/ssl/nginx.crt; then
        success "SSL certificates exist"
        docker exec nginx openssl x509 -in /etc/nginx/ssl/nginx.crt -noout -dates
    else
        error "SSL certificates missing"
    fi
}

connectivity() {
    check_container
    if docker exec nginx nc -z wordpress 9000; then
        success "WordPress connection: OK"
    else
        error "WordPress connection: FAILED"
    fi
}

logs() {
    check_container
    docker exec nginx tail -n 20 /var/log/nginx/error.log 2>/dev/null || log "No error logs"
}

case "${1:-help}" in
    "test") test ;;
    "ssl") ssl ;;
    "connectivity") connectivity ;;
    "logs") logs ;;
    *) echo "Usage: $0 {test|ssl|connectivity|logs}" ;;
esac
