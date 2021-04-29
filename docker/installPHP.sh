#!/usr/bin/env bash


set -e
set -x

# git clone https://github.com/php/php-src

SRCFILE="php-7.2.11"
SRCFILE="php-7.1.24"

mkdir -p /var/app/php_src/${SRCFILE}
tar -xzf /var/app/php_src/${SRCFILE}.tar.gz -C /var/app/php_src/${SRCFILE} --strip-components=1

cd /var/app/php_src/${SRCFILE}

# ./buildconf
# ./configure --disable-all --without-pear
./configure --without-pear --without-sqlite3 --without-pdo-sqlite --with-openssl --enable-mbstring




make -j 4

make install


export TEST_PHP_EXECUTABLE=`which php`

# echo "extension=imagick.so" > /usr/local/lib/php.ini