#!/bin/bash

# katalogi
mkdir -p ~/lemp-lab12/nginx ~/lemp-lab12/php ~/lemp-lab12/secrets
cd ~/lemp-lab12

# dockercompose
cat > docker-compose.yml << 'EOF'

services:
  nginx:
    image: nginx:1.25-alpine
    ports:
      - "4001:80"
    volumes:
      - ./nginx/default.conf:/etc/nginx/conf.d/default.conf
      - ./php:/var/www/html
    networks:
      - frontend
      - backend
    depends_on:
      - php

  php:
    image: php:8.3-fpm
    volumes:
      - ./php:/var/www/html
    networks:
      - backend

  mysql:
    image: mysql:8.4
    secrets:
      - mysql_root_password
      - mysql_database
      - mysql_user
      - mysql_password
    environment:
      MYSQL_ROOT_PASSWORD_FILE: /run/secrets/mysql_root_password
      MYSQL_DATABASE_FILE: /run/secrets/mysql_database
      MYSQL_USER_FILE: /run/secrets/mysql_user
      MYSQL_PASSWORD_FILE: /run/secrets/mysql_password
    networks:
      - backend

  phpmyadmin:
    image: phpmyadmin:5.2
    ports:
      - "127.0.0.1:6001:80"
    environment:
      PMA_HOST: mysql
      PMA_USER_FILE: /run/secrets/mysql_user
      PMA_PASSWORD_FILE: /run/secrets/mysql_password
    secrets:
      - mysql_user
      - mysql_password
    networks:
      - frontend
      - backend

networks:
  frontend:
  backend: 

secrets:
  mysql_root_password:
    file: ./secrets/mysql_root_password.txt
  mysql_database:
    file: ./secrets/mysql_database.txt
  mysql_user:
    file: ./secrets/mysql_user.txt
  mysql_password:
    file: ./secrets/mysql_password.txt
EOF

# nginx conf
cat > nginx/default.conf << 'EOF'
server {
    listen 80;
    server_name localhost;

    root /var/www/html;
    index index.php index.html index.htm;

    location / {
        try_files $uri $uri/ /index.php?$query_string;
    }

    location ~ \.php$ {
        include fastcgi_params;
        fastcgi_pass php:9000;
        fastcgi_param SCRIPT_FILENAME /var/www/html$fastcgi_script_name;
        fastcgi_param DOCUMENT_ROOT /var/www/html;
    }
}
EOF

# index.php
cat > php/index.php << 'EOF'
<?php
echo "<h1>LEMP Stack - Lab12 & Lab13 PAwCO</h1>";
phpinfo();
?>
EOF

# secrets
echo "rootpassword" > secrets/mysql_root_password.txt
echo "testdb" > secrets/mysql_database.txt
echo "testuser" > secrets/mysql_user.txt
echo "testpassword" > secrets/mysql_password.txt

# uruchomienie
docker compose up -d
echo "Main application: http://localhost:4001"
echo "phpMyAdmin: http://localhost:6001"



#windows test
#curl -I http://172.18.180.171:6001
#bash script.sh