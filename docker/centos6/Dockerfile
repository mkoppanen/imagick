FROM centos:6

USER root

# Get Debian up-to-date
#RUN apt-get update -qq \
 #   && DEBIAN_FRONTEND=noninteractive apt-get install -y \
 #   apt-transport-https autoconf bison bsdmainutils ca-certificates curl \
 #   gcc git gnupg lsb-release make pkg-config re2c wget \
 #   libpng-dev libjpeg-dev ghostscript libxml2-dev libfreetype6-dev


# Make the default directory you
WORKDIR /var/app

CMD tail -f /var/app/README.md

