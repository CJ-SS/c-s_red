#include "head.h"

void regis(int s,user *k)
{
	cout<<"please enter one user name:"<<endl;
	cin>>k->name;
	cout<<"please enter password"<<endl;
	cin>>k->password;
	send(s,k,sizeof(k),0);
	int n;
	recv(s,&n,4,0);
	switch(n){
		case 0:
			cout<<"regiser success"<<endl;
			break;
		case 1:
			cout<<"user name has been used!"<<endl;
			break;
		case 2:
			cout<<"register erro!"<<endl;
			break;
		default:
			break	;
	}
}


void login(int s,user *k)
{
	cout<<"please enter one user name:"<<endl;
	cin>>k->name;
	cout<<"please enter password"<<endl;
	cin>>k->password;
	send(s,k,sizeof(k),0);
	int n;
	recv(s,&n,4,0);
	switch(n){
		case 0:
			cout<<"login success"<<endl;
			red_group(s,k);
			break;
		case 1:
			cout<<"don't find user name!"<<endl;
			break;
		case 2:
			cout<<"password erro!"<<endl;
			break;
		default:
			break	;
	}
}
