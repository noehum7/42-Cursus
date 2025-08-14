FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx openssl

COPY conf/nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=ES/ST=Madrid/L=Madrid/O=42School/OU=Student/CN=nporras-.42.fr/emailAddress=nporras-@student.42malaga.com" \
    && chmod 600 /etc/nginx/ssl/nginx.key \
    && chmod 644 /etc/nginx/ssl/nginx.crt

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]