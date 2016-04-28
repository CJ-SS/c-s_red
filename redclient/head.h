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
	char group_name[30];
	int group_id;
	int red_num;
	float red_money;	
};

class group{
public:
	char group_name2[100][30];
	int group_id2[100];
};
