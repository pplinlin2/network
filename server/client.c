#include "utils.h"

int main()
{
	int sockfd, ret;
	struct sockaddr_in addr;
	char buf[MAX];
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0); // man socket
	if(sockfd < 0)
		return -1;
	dbmsg("create an endpoint for comm. success.");

	bzero(&addr, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET; // man 7 ip
	addr.sin_port = htons(SERVER_PORT);
	inet_aton(SERVER_IP, &addr.sin_addr); // man inet_aton
	ret = connect(sockfd, (const struct sockaddr *)&addr, sizeof(addr)); // man connect
	if(ret < 0)
		return -1;
	dbmsg("initiate a connection on a socket success.");

	while((ret = read(sockfd, buf, MAX)) > 0){
		buf[ret - 1] = '\0';
		dbmsg("%s", buf);
	}

	close(sockfd);

	return 0;
}
