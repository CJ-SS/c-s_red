#include "head.h"

void sdelete(char b[],MYSQL *p)
{
	char aa[1024]="delete from us where us_name ='";
	strcat(aa,b);
	strcat(aa,"'");
	cout<<aa<<endl;
	mysql_query(p,aa);
}

void regis(int n,user *k)
{
	MYSQL *p;
	p = mysql_init(NULL);
	p = mysql_real_connect(p,"localhost","rick","111111","Red_bag",0,NULL,0);
	if(p)
	{ 
		char aa[1024]="select us_name from us where us_name ='";
		strcat(aa,k->name);
		strcat(aa,"'");
		cout<<aa<<endl;
		if(!(mysql_query(p,aa)))
		{
		MYSQL_RES *res_ptr;
		res_ptr = mysql_store_result(p);
		if(res_ptr)
		{
			if((unsigned long)mysql_num_rows(res_ptr))
			{
				cout<<(unsigned long)mysql_num_rows(res_ptr)<<endl;
				int i=1;
				send(n,&i,1,0);
			}
			else
			{	
			char bb[1024]="insert into us(us_name) values(\"";
			strcat(bb,k->name);
			strcat(bb,"\")");
			cout<<bb<<endl;
			if(!(mysql_query(p,bb)))
			{
				char cc[1024]="insert into us(us_passward) values(\"";
				strcat(cc,k->password);
				strcat(cc,"\")");
				cout<<cc<<endl;
				if(!(mysql_query(p,cc)))
				{
					int i=0; send(n,&i,1,0);
				}
				else{sdelete(k->name,p);int i=2;send(n,&i,1,0);}
			}
			else{sdelete(k->name,p); int i=2; send(n,&i,1,0);}						
			}
		}
		}
		else{	int i=2; send(n,&i,1,0);}						
	}
}
