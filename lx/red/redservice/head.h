#include <netdb.h>
#include <iostream>
#include <errno.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <arpa/inet.h>
#include "mysql.h"


using namespace std;

class user{
public:
	char name[30];
	char password[30];
	int sig;
};
