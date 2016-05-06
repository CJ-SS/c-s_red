#include "head.h"

void regis(int,user*,int);
void login(int,user*,int);
void pout()
{
	cout<<"*************************"<<endl;
	cout<<"1.register"<<endl;
	cout<<"2.login"<<endl;
	cout<<"*************************"<<endl;	
}

int main(int argc,char *argv[])
{
while(1){
	struct sockaddr_in sin;
	int s;
	user k;
	s = socket(AF_INET,SOCK_STREAM,0);
	sin.sin_family=AF_INET;
	sin.sin_port=htons(4000);
	sin.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(s,(struct sockaddr *)&sin,sizeof(sin));	
	pout();
	int n;
	cin>>k.sig;
	switch(k.sig)
	{
		case 1:
			regis(s,&k,sizeof(k));
			break;
		case 2:
			login(s,&k,sizeof(k));
			break;
		default:
			break;
	}
}
}


