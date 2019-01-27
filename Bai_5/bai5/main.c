#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

char *file_output="output.txt";
char data[100];
int counter=0;

char *strrev(char *str);

void signal_handler_parent(int signum){

	int i=0;
	pid_t ppid = getpid();
	sleep(1);
	FILE *fptr = fopen(file_output,"a+");
	if(fptr==NULL){
		printf("Cannot open file parent\n");
		return;
	}
	fseek(fptr,0,SEEK_END);
	fgets(data,strlen(data),fptr);

	char *token = strtok(data," ");
	if(token!=NULL){
		token = strtok(NULL," ");
		if(token!=NULL){
			counter = atoi(token) ;
			counter += 1;
		}
	}
	fseek(fptr,0,SEEK_END);
	sprintf(data,"%d %d\n",ppid,counter);
	printf("Parent: %s\n",data );
	fwrite(data,sizeof(char),strlen(data),fptr);

	fclose(fptr);
	
	kill(ppid+1,12);
}
void signal_handler_child(int signum){
	int i=0;
	pid_t cpid = getpid();
	sleep(1);
	setpgid(cpid, cpid-1);
	FILE *fptr = fopen(file_output,"a+");
	if(fptr==NULL){
		printf("Cannot open file child\n");
		return;
	}
	fseek(fptr,0,SEEK_END);
	fgets(data,strlen(data),fptr);

	printf("Child Read From Father: %s\n", data);

	char *token = strtok(data," ");
	if(token!=NULL){
		token = strtok(NULL," ");
		if(token!=NULL){
			counter = atoi(token) ;
			counter += 1;
		}
	}
	fseek(fptr,0,SEEK_END);
	sprintf(data,"%d %d\n",cpid,counter);
	printf("Child: %s\n",data );
	fwrite(data,sizeof(char),strlen(data),fptr);

	fclose(fptr);
	
	kill(cpid-1,12);
}

int main(){
	pid_t fpid = fork();
	if(fork<0){
		printf("Cannot create child\n");
		return -1;
	}
	if(fpid!=0){
		pid_t ppid = getpid();
		setpgid(ppid, ppid);
		printf("Parent, PID: %d with %d\n",getpid(),fpid);
		signal(12,signal_handler_parent);

		FILE *fptr = fopen(file_output,"w+");
		if(fptr==NULL){
			printf("Cannot open file parent\n");
			return -1;
		}
		sprintf(data,"%d %d\n",getpid(),counter);
		fwrite(data,sizeof(char),strlen(data),fptr);
		fclose(fptr);
		sleep(2);
		counter += 1;

		printf("Send signal to %d\n", ppid+1);
		kill(ppid+1,12);

		while(1);
	}
	else{
		pid_t cpid = getpid();
		printf("Child, PID: %d\n",cpid);
		signal(12,signal_handler_child);
		while(1);
	}
	return 0;
}

char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}