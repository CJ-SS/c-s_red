#include "head.h"
using namespace std;


void regis(int s)
{
lp:
	send(s,"1",1,0);
	cout<<"please enter one user name:"<<endl;
	char name[30];
	cin>>name;
	send(s,name,strlen(name),0);
	int n;
	char k;
	n = recv(s,k,1,0);
	if(a == "1")
	{
		cout<<"please enter password":<<endl;
		char password[30];
		cin>>password;
		send(s,passwoed,strlen(password),0)
		char j;
		int m = recv(s,j,1,0);
		if(j == "1")
		{
			cout<<"register success! "<<endl;
			return ;
		}
	}
	else{
		cout<<"User name has been used!"<<endl;
		goto 	lp;
	}
}
