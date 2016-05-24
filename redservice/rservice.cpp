#include "head.h"

void regis(int,user*,int);
void login(int,user*,int);

int main(int argc,char *argv[])
{
	struct sockaddr_in sin;
        int s;
        user k;
        s = socket(AF_INET,SOCK_STREAM,0);
        sin.sin_family=AF_INET;
        sin.sin_port=htons(4000);
        sin.sin_addr.s_addr=inet_addr("127.0.0.1");
	if(bind(s,(struct sockaddr *)&sin,sizeof(sin)) != 0)
	{ cout<<"bind erro"<<endl;
		return (0);
	}
	listen(s,10);
	 while(1)
        {
                int n;
                n = accept(s,0,0);
                user k;
                memset(&k,0,sizeof(k));
                cout<<sizeof(k)<<endl;
                recv(n,&k,sizeof(k),0);
                cout<<k.name<<endl;
                cout<<k.password<<endl;
                cout<<k.sig<<endl;
                switch(k.sig)
                {
                        case 1:
                                regis(n,&k,sizeof(k));
                                break;
			case 2:
				login(n,&k,sizeof(k));
                        default:
                                break;
                }
        }	
}
