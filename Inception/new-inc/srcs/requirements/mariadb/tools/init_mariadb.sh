#!/bin/bash

DB_PASSWORD=$(cat /run/secrets/db_password)
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

DB_NAME=${MYSQL_DATABASE}
DB_USER=${WORDPRESS_DB_USER}

chown -R mysql:mysql /var/lib/mysql
chmod 755 /var/lib/mysql

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
    mysqld --user=mysql --datadir=/var/lib/mysql &
    while ! mysqladmin ping --silent; do
        sleep 1
    done
    mysql -u root << EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';

CREATE DATABASE IF NOT EXISTS ${DB_NAME};

CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';

DROP DATABASE IF EXISTS test;
DELETE FROM mysql.user WHERE User='';
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');

FLUSH PRIVILEGES;
EOF
    mysqladmin -u root -p${DB_ROOT_PASSWORD} shutdown
fi

exec mysqld --user=mysql --datadir=/var/lib/mysql