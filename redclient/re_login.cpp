#include "head.h"
void red_group(int,user*);

void regis(int s,user *k,int l)
{
	cout<<"please enter one user name:"<<endl;
	cin>>k->name;
	cout<<"please enter password"<<endl;
	cin>>k->password;
	send(s,k,l,0);
	int n;
	recv(s,&n,4,0);
	switch(n){
		case 7:
			cout<<"regiser success"<<endl;
			break;
		case 8:
			cout<<"user name has been used!"<<endl;
			break;
		case 9:
			cout<<"register erro!"<<endl;
			break;
		default:
			break	;
	}
}


void login(int s,user *k,int l)
{
	cout<<"please enter one user name:"<<endl;
	cin>>k->name;
	cout<<"please enter password"<<endl;
	cin>>k->password;
	send(s,k,l,0);
	int n;
	recv(s,&n,4,0);
	switch(n){
		case 7:
			cout<<"login success"<<endl;
			red_group(s,k);
			break;
		case 8:
			cout<<"don't find user name!"<<endl;
			break;
		case 9:
			cout<<"login erro!"<<endl;
			break;
		case 10:
			cout<<"password erro!"<<endl;
			break;
		default:
			break	;
	}
}
