#include "utils.h"

int main()
{
	int sockfd, ret, connfd;
	struct sockaddr_in addr;
	char buf[MAX];
	time_t tick;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		return -1;
	dbmsg("create an endpoint for communication");

	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port   = htons(SERVER_PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	ret = bind(sockfd, (const struct sockaddr *)&addr, sizeof(addr));
	if(ret < 0)
		return -1;
	dbmsg("bind a name to a socket");

	listen(sockfd, 10); // man listen

	while(1){
		connfd = accept(sockfd, NULL, NULL);
		if(connfd < 0)
			return -1;
		dbmsg("accept a connection on a socket");

		tick = time(NULL);
		snprintf(buf, sizeof(buf), "%s", ctime(&tick));
		write(connfd, buf, strlen(buf));
		close(connfd);
	}

	return 0;
}
