#include "head.h"
using namespace std;

int main()
{
	struct sockaddr_in sin;
	int s;
	s = socket(AF_INET,SOCK_STREAM,0);
	sin.sin_family=AF_INET;
	sin.sin_port=htons(4000);
	sin.sin_addr.s_addr=inet_addr("127.0.0.1");
	if(bind(s,(struct sockaddr *)&sin,sizeof(sin)) != 0)
	{
		cout<<"bind erro"<<endl;
		return (0);
	}
	listen(s,10);
	while(1)
	{
		int n;
		n = accept(s,0,0);
		char num;
		recv(n,num,1,0);
		swich(num)
		{
			case "1":
		}
	}
}

bool mysql_on(MYSQL *p)
{
	p = mysql_init(NULL);
	p = mysql_real_connect(p,"localhost","rick","111111","Red_bag",0,NULL,0);
	if(!p)
	{
		return false;
	}
	else{
		return true;
	}
}

void regis(int n)
{
	char name[30];
	recv(n,name,30,0);
	MYSQL *p;
	if(mysql_on(p))
	{ 
}
