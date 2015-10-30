#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define dbmsg(fmt, arg ...) printf("%s:%s[%d]: "fmt"\n", __FILE__, __FUNCTION__, __LINE__, ##arg)
#define MAX 1024
#define SERVER_PORT 13999
#define SERVER_IP "127.0.0.1"
