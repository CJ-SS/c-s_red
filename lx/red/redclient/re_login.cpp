#include "head.h"

void regis(int s,user *k)
{
	cout<<"please enter one user name:"<<endl;
	cin>>k->name;
	cout<<"please enter password"<<endl;
	cin>>k->password;
	send(s,k,64,0);
	int n;
	recv(s,&n,1,0);
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
