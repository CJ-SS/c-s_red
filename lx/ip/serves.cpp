#include <netdb.h>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
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
	bind(s,(struct sockaddr *)&sin,sizeof(sin));
	listen(s,10);
	while(1){
		int n;
		n = accept(s,0,0);
		int k;
		k = 0;
		recv(n,&k,sizeof(k),0);
		cout<<k<<endl;
	}
}
