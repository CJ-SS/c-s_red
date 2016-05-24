#include <netdb.h>
#include <iostream>
#include <errno.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <arpa/inet.h>

using namespace std;

int main(int argc,char *argv[])
{
	struct sockaddr_in sin;
	int s;
	while(1)
	{
	s = socket(AF_INET,SOCK_STREAM,0);
	sin.sin_family=AF_INET;
	sin.sin_port=htons(4000);
	sin.sin_addr.s_addr=inet_addr("127.0.0.1");
		connect(s,(struct sockaddr *)&sin,sizeof(sin));
		int n = 3;
		send(s,&n,4,0);
	}
}
