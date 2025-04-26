FROM php:8.3-fpm

# Установка необходимых пакетов и расширений PHP
RUN apt-get update && apt-get install -y \
    default-mysql-client \
    telnet \
    && docker-php-ext-install mysqli

RUN apt-get clean && rm -rf /var/lib/apt/lists/*

# Копирование кода в контейнер
COPY ./code /var/www/html
