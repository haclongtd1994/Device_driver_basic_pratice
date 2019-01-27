#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int uid_current=1,uid_new=1;

void my_exit(){
	system("/usr/bin/id");
	uid_new = setuid(uid_current);
	if(uid_new){
		printf("Cannot change to normal user: %d\n",getuid());
	}
	printf("Back current UID%d\n", getuid());
}

//su dung system
int main(){
	printf("Program to up down or set ip port enp7s0\n");
	uid_current=getuid();
	printf("Current UID %d\n", uid_current);
	printf("Change to super user to config ip port\n");
	system("/usr/bin/id");
	uid_new = setuid(0);
	if(uid_new){
		printf("Cannot change to super user\n");
		return -1;
	}
	printf("Change to super user successful\n");

	//register exit function to change super user to current user
	if(atexit(my_exit)!=0){
		printf("Cannot register to function exit\n");
		return -1;
	}
	printf("Register successful\n");

	char data[200];
	char ip_new[100],ip_data[1024];

	while(1){
		printf("Select: \"check\" \"up\" \"down\" \"set\" or \"exit\" ip port\n");
		scanf("%s",data);

		if(!strcmp(data,"check")){
			system("ifconfig");
		}
		else if(!strcmp(data,"up")){
			system("/sbin/ifconfig enp7s0 up");
		}
		else if(!strcmp(data,"down")){
			system("/sbin/ifconfig enp7s0 down");
		}else if(!strcmp(data,"set")){
			printf("Type new ip for enp7s0\n");
			scanf("%s",ip_new);
			sprintf(ip_data,"ifconfig enp7s0 %s netmask 255.255.255.0",ip_new);
			printf("%s\n", ip_data);
			system(ip_data);
		}
		else if(!strcmp(data,"exit"))	return 0;
		else{
			printf("Select: \"check\" \"up\" \"down\" \"set\" or \"exit\" ip port\n");
		}

	}
}