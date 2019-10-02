FROM ubuntu:18.04

# Don't interact during installation
# This is espesially important for tz packet installation (php deps)
ENV DEBIAN_FRONTEND=noninteractive 

# Allow composer run from root user (default user in docker)
# The composer is required by php lib installation
ENV COMPOSER_ALLOW_SUPERUSER 1

# Setup thrift version be used
ENV THRIFT_VERSION v0.12.0
ENV THRIFT_SRC https://github.com/apache/thrift/archive/${THRIFT_VERSION}.tar.gz



# The script install and setup all deps + build thrift
RUN buildDeps=" \
		automake \
		bison \
		curl \
		flex \
		g++ \
		php7.2-dev \
		php7.2-xml \
		git \
		composer \
		libboost-dev \
		libboost-filesystem-dev \
		libboost-program-options-dev \
		libboost-system-dev \
		libboost-test-dev \
		libevent-dev \
		libssl-dev \
		libtool \
		make \
		pkg-config \
	"; \
	apt-get update && \
    apt-get install -y --no-install-recommends $buildDeps && \
    rm -rf /var/lib/apt/lists/* \
	&& curl -k -sSL "${THRIFT_SRC}" -o thrift.tar.gz \
	&& mkdir -p /usr/src/thrift \
	&& tar zxf thrift.tar.gz -C /usr/src/thrift --strip-components=1 \
	&& rm thrift.tar.gz \
	&& cd /usr/src/thrift \
	&& ./bootstrap.sh \
	&& PHP_PREFIX=/usr/lib/php/Thrift ./configure \
	&& make \
	&& make install \
	&& cd / \
	&& rm -rf /usr/src/thrift \
	&& rm -rf /var/cache/apt/* \
	&& rm -rf /var/lib/apt/lists/* \
	&& rm -rf /tmp/* \
	&& rm -rf /var/tmp/*

# By default start up apache in the foreground, 
# override with /bin/bash for interative.
CMD [ "thrift" ]