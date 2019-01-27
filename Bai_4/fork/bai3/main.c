#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int main(){
	int so=0;

	pid_t pid = fork();
	while(1){
		if(pid!=0){
			printf("Parent\n");
			so++;
			printf("Parent %d\n", so);
			sleep(1);
		}
		else{
			printf("Child\n");
			so=so+2;
			printf("Child %d\n", so);
			sleep(1);
		}
	}
	
}