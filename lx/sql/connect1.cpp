#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include"mysql.h"
using namespace std;

#define NAMELINE 30


const char username[NAMELINE]={"zhaohu"};	//jiekou



int main(int argc,char *argv[])
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
		cout<<"fff"<<endl;
		int rew = mysql_query(p,"SELECT us_name from us where us_name = 'zhaohu'");	//jiekou
		if(rew)
		{
			cout<<"select erro"<<endl;
		}
		else{
//		cout<<"fff"<<endl;
//			res_ptr=mysql_use_result(p);
//			sqlrow = mysql_fetch_row(res_ptr);
//			if(strcmp(username,sqlrow[0]) == 0)
//			{
				cout<<"PERFECT"<<endl;
//			}		
		}
	}
//	mysql_free_result(res_ptr);
	
	
	mysql_close(p);
	return EXIT_SUCCESS;
}
