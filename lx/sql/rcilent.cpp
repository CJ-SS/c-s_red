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

void pout()
{
	cout<<"*************************"<<endl;
	cout<<"1.register"<<endl;
	cout<<"2.login"<<endl;
	cout<<"*************************"<<endl;	
}

int main(int argc.char argv[])
{
	pout;
	struct sockaddr_in sin;
	int s;
	s = socket(AF_INET,SOCK_STREAM,0);
	sin.sin_family=AF_INET;
	sin.sin_port=htons(4000);
	sin.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(s,(struct sockaddr *)&sin,sizeof(sin));	
while(1){
	int n;
	cin>>n;
	swich(n)
	{
		case 1:
			regis(s);
		case 2:
		default:
	}
}
