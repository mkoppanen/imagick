FROM centos:7

USER root

RUN yum -y install autoconf bison curl \
  gcc git gnupg make re2c wget \
  ghostscript libxml2-dev

# Make the default directory you
WORKDIR /var/app

CMD tail -f /var/app/README.md

