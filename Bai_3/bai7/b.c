#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int main(){
	pid_t pid=getpid();
	pid_t sid = getsid(pid);
	char data[10];
	//Write to /proc/*pid of the program*/fd/0. The fd subdirectory contains the descriptors of all the opened files and file descriptor 0 is the standard input (1 is stdout and 2 is stderr).
	printf("CT2:\n");
	printf("%d\n", sid);
	scanf("%9s",data);
	printf("%s\n", data);
	return 0;
}