FROM debian:bullseye

RUN apt-get update && apt-get install -y mariadb-server mariadb-client && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    chmod 777 /var/run/mysqld && \
    chown -R mysql:mysql /var/lib/mysql

RUN sed -i 's/bind-address.*=.*127\.0\.0\.1/bind-address = 0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf

COPY tools/init_mariadb.sh /usr/local/bin/init_mariadb.sh
RUN chmod +x /usr/local/bin/init_mariadb.sh

EXPOSE 3306

CMD ["/usr/local/bin/init_mariadb.sh"]