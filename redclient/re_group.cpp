#include "head.h"


void create_group(int n,user *k)
{
	cout<<"please enter one group name:"<<endl;
	cin>>k->group_name;	
	send(s,k,sizeof(k),0);
	int l;
	recv(s,&l,sizeof(l),0);
	if(l == 1)
	{ cout<<"create success"<<endl;}
	return ;
}

void see_group(int s,user *k)
{
	send(s,k,sizeof(k),0);
	group l;
	recv(s,&l,sizeof(l),0);
	int i=0;
	while(1)
	{
		if(l.group_name2[i] == null && i>99)
		{return 0;}
		cout<<l.group_id2[i]<<" : "<<l.group_name2[i]<<endl;
		i++;
	}
}
void redbag(int s,user *k)
{
	red_group(s,k);
	cout<<"which are you?(please int id)"<<endl;
	cin>>k->group_id;
	cout<<"redbag num:"<<endl;
	cin>>k->red_num;
	cout<<"redbag money:"<<endl;
	cin>>k->red_money;
	send(s,k,sizeof(k),0);
	int n;
	recv(s,&n,4,0);
	switch(n)
	{
		case 1:
			cout<<"group_id error"<<endl;
		case 2:
			cout<<"R_num :"<<k->red_num<<"    R_money:"<<k->red_money<<endl;
	}
}

void red_group(int s,user *k)
{
	while(1)
	{
		cin>>k.sig;
		switch(n)
		{
			case 3:
				create_group(s,k);
				break;
			case 4:
				see_group(s,k);
				break;
			case 5:
				redbag(s,k);
				break;	
			default:
				return ;
				break;
		}	
	}
}
