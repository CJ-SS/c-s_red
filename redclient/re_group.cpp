#include "head.h"

void red_group(int,user*);

void create_group(int s,user *k)
{
	group m;
	m.sig = k->sig;
	cout<<"please enter one group name:"<<endl;
	cin>>m.group_name;	
	send(s,&m,sizeof(m),0);
	int l;
	recv(s,&l,sizeof(l),0);
	if(l == 1)
	{ cout<<"create success"<<endl;}
	else
	{ cout<<"create erro!"<<endl;}
	return ;
}

void see_group(int s,user *k)
{
	send(s,k,sizeof(k),0);
	group_name l;
	recv(s,&l,sizeof(l),0);
	int i=0;
	while(1)
	{
		if(l.group_name[i] == "\0" && i>99)
		{return ;}
		cout<<l.group_id[i]<<" : "<<l.group_name[i]<<endl;
		i++;
	}
}
void redbag(int s,user *k)
{
	red_group(s,k);
	red m;
	cout<<"which are you?(please int id)"<<endl;
	cin>>m.group_id;
	cout<<"redbag num:"<<endl;
	cin>>m.red_num;
	cout<<"redbag money:"<<endl;
	cin>>m.red_money;
	m.us_id = k->us_id;
	m.sig = k->sig;
	send(s,&m,sizeof(m),0);
	int n;
	recv(s,&n,4,0);
	switch(n)
	{
		case 1:
			cout<<"group_id error"<<endl;
		case 2:
			cout<<"R_num :"<<m.red_num<<"    R_money:"<<m.red_money<<endl;
	}
}

void red_group(int s,user *k)
{
	while(1)
	{
		cin>>k->sig;
		switch(k->sig)
		{
			case 1:
				create_group(s,k);
				break;
			case 2:
				see_group(s,k);
				break;
			case 3:
				redbag(s,k);
				break;	
			default:
				return ;
				break;
		}	
	}
}
