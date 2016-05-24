#include<stdio.h>
#include<stdlib.h>

#include<mysql/mysql.h>

int main(int argc,char *argv[])
{
	MYSQL *p;
	p = mysql_init(NULL);
//	if(!p)
//	{
//		fprintf(stderr,"mysql_init failed\n");
//		return EXIT_FAILURE;
//	}
	p = mysql_real_connect(p,"localhost","rick","111111","Red_bag",0,NULL,0);
	if(p)
	{
		printf("ppppppp\n");
	}
	else
	{
		printf("qqqqqqq\n");
	}
	mysql_close(p);
	return EXIT_SUCCESS;
}
