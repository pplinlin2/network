SUDO := sudo
INSTALL := $(SUDO) apt-get install

all:
	@echo 'usage:'
	@echo '  make check'
	@echo '  make build'

build:
	$(CC) client.c -o client
	./client

check:
	$(INSTALL) xinetd
	$(SUDO) sed -i 's/disable\t\t= yes/disable\t\t= no/g' /etc/xinetd.d/daytime
	$(SUDO) /etc/init.d/xinetd restart
