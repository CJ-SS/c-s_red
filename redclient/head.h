#include <netdb.h>
#include <errno.h>
#include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <arpa/inet.h>

using namespace std;

class user{
public:
	char name[30];
	char password[30];
	int us_id;
	int sig;
};

class group{
public:
	int sig;
	int us_id;
	char group_name[30];
	int group_id;
};

class red{
public:
	int sig;
	int us_id;
	int group_id;
	int red_num;
	float red_money;
};

class group_name{
public:
	char group_name[100][30];
	int group_id[100];
};
