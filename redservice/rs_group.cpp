#include "head.h"

void redgroup(int n,user *k,int l,MYSQL *p)
{
	int s;
	recv(n,&s,sizeof(s),0);
	switch(s)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			return ;
	}
}
