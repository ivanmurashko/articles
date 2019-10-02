FROM thriftbuilder

ENV DEBIAN_FRONTEND=noninteractive 

RUN deps=" \
		apache2 \
		libapache2-mod-php7.2 \
	"; \
    apt-get update && \
    apt-get install -y --no-install-recommends $deps && \
    rm -rf /var/lib/apt/lists/* \
	&& cd / \
	&& rm -rf /usr/src/thrift \
	&& rm -rf /var/cache/apt/* \
	&& rm -rf /var/lib/apt/lists/* \
	&& rm -rf /tmp/* \
	&& rm -rf /var/tmp/*

# Enable apache mods.
RUN a2enmod php7.2
RUN a2enmod rewrite

# Update the PHP.ini file, enable <? ?> tags and quieten logging.
RUN sed -i "s/short_open_tag = Off/short_open_tag = On/" \
/etc/php/7.2/apache2/php.ini
RUN sed -i "s/error_reporting = .*$/error_reporting = E_ERROR | E_WARNING | E_PARSE/" \
/etc/php/7.2/apache2/php.ini

# Manually set up the apache environment variables
ENV APACHE_RUN_USER www-data
ENV APACHE_RUN_GROUP www-data
ENV APACHE_LOG_DIR /var/log/apache2
ENV APACHE_LOCK_DIR /var/lock/apache2
ENV APACHE_PID_FILE /var/run/apache2.pid

# Expose apache.
EXPOSE 80

# Copy this repo into place.
COPY ./php /var/www/site
COPY ./thrift/proto.thrift /var/www/site

# Generate the required thrift files
RUN \
	cd /var/www/site && \
    thrift -r --gen php proto.thrift  

# Update the default apache site with the config we created.
ADD ./apache2/apache-config.conf /etc/apache2/sites-enabled/000-default.conf

# By default start up apache in the foreground, 
# override with /bin/bash for interative.
CMD /usr/sbin/apache2ctl -D FOREGROUND