#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(){
	printf("Program to kill another program\n");
	pid_t pid = fork();
	if(pid==0){
		printf("Process child\n");
		if(system("ps -e -opid,command | grep ./main > output.txt")) return -1;
		return 0;
	}
	else{
		int stat;
		char *path="output.txt";
		printf("Process parent\n");
		wait(&stat);
		if(WIFEXITED(stat)){
			if(!WEXITSTATUS(stat)){
				char data[1024];
				char *token;
				FILE *fptr = fopen(path,"r");
				if(fptr==NULL){
					printf("Cannot open file\n");
					return -1;
				}
				fread(data,sizeof(char),strlen(data),fptr);
				token = strtok(data," ");
				if(token!=NULL){
					int pid = atoi(token);
					kill(pid,2);
					printf("Sended signal: 2 to PID: %d\n", pid);
				}
			}
		}

	}
}