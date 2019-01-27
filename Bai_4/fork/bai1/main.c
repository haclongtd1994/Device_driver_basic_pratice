#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int main(){
	pid_t pid = fork();
	if(pid!=0){
		printf("I am parent   Fork: %d      PID: %d\n",pid,getpid());
		return 0;
	}
	else{
		printf("i am child    Fork: %d      PID: %d\n",pid,getpid());
		return 0;
	}
}