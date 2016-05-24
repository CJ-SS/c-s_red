#include "head.h"
void redgroup(int,user *,int,MYSQL *);

void sdelete(char *b,MYSQL *p)
{
        char aa[1024]="delete from us where us_name ='";
        strcat(aa,b);
        strcat(aa,"'");
        cout<<aa<<endl;
        mysql_query(p,aa);
}

void regis(int n,user *k,int l)
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
                                int i=8;
                                send(n,&i,sizeof(i),0);
                        }
                        else
                        {
                        char bb[1024]="insert into us(us_name,us_password) values(\"";
                        strcat(bb,k->name);
                        strcat(bb,"\",\"");
			strcat(bb,k->password);
			strcat(bb,"\")");
                        cout<<bb<<endl;
                        if(!(mysql_query(p,bb)))
                        {
                        	//char cc[1024]="insert into us(us_password) values(\"";
                        	//strcat(cc,k->password);
                        	//strcat(cc,"\")");
                                //cout<<cc<<endl;
                                //if(!(mysql_query(p,cc)))
                                //{
                                        int i=7; send(n,&i,sizeof(i),0);
                                //}
                                //else{sdelete(k->name,p);int i=9;send(n,&i,sizeof(i),0);}
                        }
                        else{sdelete(k->name,p); int i=9; send(n,&i,sizeof(i),0);}
                        }
                }
                }
                else{   int i=9; send(n,&i,sizeof(i),0);}
        }
	else{int i=9; send(n,&i,sizeof(i),0);}
}




void login(int n,user *k,int l)
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
                        if(!(unsigned long)mysql_num_rows(res_ptr))
                        {
                                cout<<(unsigned long)mysql_num_rows(res_ptr)<<endl;
                                int i=8;
                        	send(n,&i,sizeof(i),0);
                        }
			else
                        {
				cout<<(unsigned long)mysql_num_rows(res_ptr)<<endl;
                		char bb[1024]="select us_password from us where us_password ='";
              			strcat(bb,k->password);
              			strcat(bb,"'");
				if(!(mysql_query(p,bb)))
				{
					res_ptr = mysql_store_result(p);
                			if(res_ptr)
               				{
                			        if(!(unsigned long)mysql_num_rows(res_ptr))
						{
            						cout<<(unsigned long)mysql_num_rows(res_ptr)<<endl;
							int i=10;
                        	      			send(n,&i,sizeof(i),0);
                       				}
						else
						{
							char cc[1024]="select us_id from us where us_name ='";
							strcat(cc,k->name);
                  					strcat(cc,"'");
                  					cout<<cc<<endl;
							mysql_query(p,cc);
							res_ptr = mysql_store_result(p);
							MYSQL_ROW sqlow;
							while(sqlow = mysql_fetch_row(res_ptr))
							{
								cout<<"2222"<<endl;
							}
							cout<<sqlow[0]<<endl;
							int i=7;
							send(n,&i,sizeof(i),0);
							//redgroup(n,k,l,p);
						}
					}
                			else{   int i=9; send(n,&i,sizeof(i),0);}
				}
                		else{   int i=9; send(n,&i,sizeof(i),0);}
                        }
                }
                }
                else{   int i=9; send(n,&i,sizeof(i),0);}
        }
}

