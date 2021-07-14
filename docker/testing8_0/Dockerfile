FROM debian:9

USER root

# Get Debian up-to-date
RUN apt-get update -qq \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y git \
    mariadb-client wget curl \
    ca-certificates lsb-release apt-transport-https gnupg bsdmainutils


RUN echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" | tee -a /etc/apt/sources.list.d/php.list
RUN curl -L https://packages.sury.org/php/apt.gpg | apt-key add -

RUN  apt-get update -qq \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y php8.0 php8.0-common php8.0-cli php8.0-fpm \
    php8.0-mysql  php8.0-curl php8.0-xml php8.0-mbstring \
    php8.0-intl php8.0-redis php8.0-zip php8.0-sqlite \
# How weird is this? Able to use Imagick when I haven't done a release for PHP 8 yet.
    php8.0-imagick

# Make the default directory you
WORKDIR /var/app

# Run the process that this container will serve

CMD tail -f /var/app/docker/testing8_0/README.md
