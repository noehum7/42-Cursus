FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    php-fpm \
    php-mysql \
    php-curl \
    php-gd \
    php-mbstring \
    php-xml \
    php-xmlrpc \
    php-soap \
    php-intl \
    php-zip \
    wget \
    curl \
    unzip \
    netcat \
    openssl && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html
RUN wget https://wordpress.org/latest.zip && \
    unzip latest.zip && \
    mv wordpress/* . && \
    rmdir wordpress && \
    rm latest.zip && \
    chown -R www-data:www-data /var/www/html

RUN sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 9000/g' /etc/php/7.4/fpm/pool.d/www.conf

RUN mkdir -p /run/php && chown -R www-data:www-data /run/php

RUN wget https://github.com/wp-cli/wp-cli/releases/download/v2.8.1/wp-cli-2.8.1.phar -O /tmp/wp-cli.phar && \
    chmod +x /tmp/wp-cli.phar && \
    mv /tmp/wp-cli.phar /usr/local/bin/wp

COPY tools/init_wordpress.sh /usr/local/bin/init_wordpress.sh
RUN chmod +x /usr/local/bin/init_wordpress.sh

EXPOSE 9000

CMD ["/usr/local/bin/init_wordpress.sh"]