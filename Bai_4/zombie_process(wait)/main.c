#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
	char *Pathname="test.txt";
	pid_t pid = fork();
	if(pid!=0){
		int stat;
		printf("I am parent\n");
		pid_t cpid = wait(&stat);
		if( WIFEXITED(stat)) printf("Exit status: %d\n",WEXITSTATUS(stat));
		return 0;
	}
	else{
		printf("I am child\n");
		FILE *ptr = fopen(Pathname,"w");
		if(ptr==NULL){
			printf("Cannot open for write: %s\n",Pathname);
			exit(-1);
		}
		size_t kt = fwrite("Hello World",1,strlen("Hello World"),ptr);
		if(kt!=strlen("Hello World")){
			printf("Write failed with %zu size \n", kt);
			exit(-2);
		}
		fclose(ptr);
		exit(0);
	}
}