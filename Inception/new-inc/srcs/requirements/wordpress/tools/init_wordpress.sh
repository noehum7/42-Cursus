#!/bin/bash

DB_PASSWORD=$(cat /run/secrets/db_password)
DB_HOST=${WORDPRESS_DB_HOST}
DB_NAME=${WORDPRESS_DB_NAME}
DB_USER=${WORDPRESS_DB_USER}

while ! nc -z ${DB_HOST} 3306; do
    sleep 2
done

if [ ! -f /var/www/html/wp-config.php ]; then
    if [ -f /run/secrets/wp_salts ]; then
        source /run/secrets/wp_salts
    else
        AUTH_KEY=${WP_AUTH_KEY:-'your-auth-key-here'}
        SECURE_AUTH_KEY=${WP_SECURE_AUTH_KEY:-'your-secure-auth-key-here'}
        LOGGED_IN_KEY=${WP_LOGGED_IN_KEY:-'your-logged-in-key-here'}
        NONCE_KEY=${WP_NONCE_KEY:-'your-nonce-key-here'}
        AUTH_SALT=${WP_AUTH_SALT:-'your-auth-salt-here'}
        SECURE_AUTH_SALT=${WP_SECURE_AUTH_SALT:-'your-secure-auth-salt-here'}
        LOGGED_IN_SALT=${WP_LOGGED_IN_SALT:-'your-logged-in-salt-here'}
        NONCE_SALT=${WP_NONCE_SALT:-'your-nonce-salt-here'}
    fi

    cat > /var/www/html/wp-config.php << EOF
<?php
define('DB_NAME', '${DB_NAME}');
define('DB_USER', '${DB_USER}');
define('DB_PASSWORD', '${DB_PASSWORD}');
define('DB_HOST', '${DB_HOST}');
define('DB_CHARSET', 'utf8mb4');
define('DB_COLLATE', '');

define('AUTH_KEY',         '${AUTH_KEY}');
define('SECURE_AUTH_KEY',  '${SECURE_AUTH_KEY}');
define('LOGGED_IN_KEY',    '${LOGGED_IN_KEY}');
define('NONCE_KEY',        '${NONCE_KEY}');
define('AUTH_SALT',        '${AUTH_SALT}');
define('SECURE_AUTH_SALT', '${SECURE_AUTH_SALT}');
define('LOGGED_IN_SALT',   '${LOGGED_IN_SALT}');
define('NONCE_SALT',       '${NONCE_SALT}');

\$table_prefix = 'wp_';

define('WP_DEBUG', false);

if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';
EOF

    chown www-data:www-data /var/www/html/wp-config.php
    echo "wp-config.php created correctly!"
fi

exec php-fpm7.4 -F
