SUDO := sudo
INSTALL := $(SUDO) apt-get install

all:
	@echo 'usage:'
	@echo '  make check'
	@echo '  make build'

build:
	$(CC) client.c -o client
	$(CC) server.c -o server

clean:
	-rm client server
