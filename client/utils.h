#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#define dbmsg(fmt, arg ...) printf("%s:%s[%d]: "fmt"\n", __FILE__, __FUNCTION__, __LINE__, ##arg)
#define MAX 1024
