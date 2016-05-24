#include <netdb.h>
#include <errno.h>
#include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <arpa/inet.h>


using namespace std;

int main(int argc,char *argv[])
{
	struct sockaddr_in sin;
	int s;
	s = socket(AF_INET,SOCK_STREAM,0);
	sin.sin_family=AF_INET;
	sin.sin_port=htons(4000);
	sin.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(s,(struct sockaddr *)&sin,sizeof(sin));
	char bufflen[30];
	cin>>bufflen;
	send(s,bufflen,strlen(bufflen),0);
	int n;
	char buffle[20];
	n=recv(s,buffle,20,0);
	//if(n)
	//{
//		cout<<buffle<<endl;
//	}
//	while((n = recv(s,buffle,20,0)) > 0)
	write(STDOUT_FILENO,buffle,n);
	cout<<endl;
	return 0;
}
