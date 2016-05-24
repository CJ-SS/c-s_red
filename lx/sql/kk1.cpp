#include <netdb.h>
#include <iostream>
#include <errno.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <arpa/inet.h>
#include"mysql.h"

using namespace std;

bool cmp(char a[])
{
	MYSQL *p;
	
	MYSQL_RES *res_ptr;
	MYSQL_ROW sqlrow;
	p = mysql_init(NULL);
	p = mysql_real_connect(p,"localhost","rick","111111","Red_bag",0,NULL,0);
	if(!p)
	{
		cout<<"mysql connect erro"<<endl;
	}
	else{
	//	cout<<"fff"<<endl;
		char aa[1024]="select us_name from us where us_name =";
		strcat(aa,"'");
		strcat(aa,a);
		strcat(aa,"'");
//		cout<<aa<<endl;
		int rew = mysql_query(p,aa);	//jiekou
		if(rew)
		{
			cout<<"select erro"<<endl;
			return false;
		}
		else{
			res_ptr = mysql_store_result(p);
			if(res_ptr)
			{
//				cout<<"pppp"<<endl;
				sqlrow = mysql_fetch_row(res_ptr);
				cout<<sqlrow[0]<<endl;
				if(strcmp(sqlrow[0],a) == 0)
				{
					return true;
				}
			}				
		}
	}
	
	mysql_close(p);
	return false;
}

int main(int argc,char *argv[])
{
	struct sockaddr_in sin;
	int s;
	s = socket(AF_INET,SOCK_STREAM,0);
	sin.sin_family=AF_INET;
	sin.sin_port=htons(4000);
	sin.sin_addr.s_addr=inet_addr("127.0.0.1");
	if(bind(s,(struct sockaddr *)&sin,sizeof(sin)) != 0)
	{
		cout<<"b erro"<<endl;
		return (0);
	}

	listen(s,10);
	while(1){
	int n;
	n=accept(s,0,0);

	char buffle[30];
	memset(buffle,0,30);
	recv(n,buffle,30,0);
//	cout<<buffle<<endl;
	if(cmp(buffle))
	{
		char bufflen[]="perfect";
		send(n,bufflen,strlen(bufflen),0);
	}
	}
	return 0;

}
