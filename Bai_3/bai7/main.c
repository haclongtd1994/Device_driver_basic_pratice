#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "fcntl.h"

int main(){
	//step 1: get pid from popen step 2: get sid from pid step 1
	char data[100];
	pid_t pgid;
	size_t size;
	char pidline[1024];
	char *pid;
	int pidno[64];

	FILE *fptr = popen("pidof a","r");
	fgets(pidline, 1024, fptr);
	pid=strtok(pidline," ");
	if(pid!=NULL){
		pidno[0] = atoi(pid);
		printf("%d\n",pidno[0]);
		pid = strtok(NULL," ");
	}
	pclose(fptr);

	fptr = popen("pidof b","r");
	fgets(pidline, 1024, fptr);
	pid=strtok(pidline," ");
	if(pid!=NULL){
		pidno[1] = atoi(pid);
		printf("%d\n",pidno[1]);
		pid = strtok(NULL," ");
	}
	pclose(fptr);

	fptr = popen("pidof c","r");
	fgets(pidline, 1024, fptr);
	pid=strtok(pidline," ");
	if(pid!=NULL){
		pidno[2] = atoi(pid);
		printf("%d\n",pidno[2]);
		pid = strtok(NULL," ");
	}
	pclose(fptr);

	while(1){
		snprintf(data,100,"/proc/%d/fd/0",pidno[0]);
		fptr = fopen(data,"w");
		if(fptr==NULL){
			printf("file open failed: %s\n", data);
			return -1;
		}

		size = fwrite("Hello\n",1,sizeof("Hello\n"),fptr);
		if(size!=sizeof("Hello\n")){
			printf("Write failed\n");
			return -1;
		}
		snprintf(data,100,"/proc/%d/fd/0",pidno[1]);
		fptr = fopen(data,"w");
		if(fptr==NULL){
			printf("file open failed: %s\n", data);
			return -1;
		}

		size = fwrite("Hello\n",1,sizeof("Hello\n"),fptr);
		if(size!=sizeof("Hello\n")){
			printf("Write failed\n");
			return -1;
		}
		snprintf(data,100,"/proc/%d/fd/0",pidno[2]);
		fptr = fopen(data,"w");
		if(fptr==NULL){
			printf("file open failed: %s\n", data);
			return -1;
		}

		size = fwrite("Hello\n",1,sizeof("Hello\n"),fptr);
		if(size!=sizeof("Hello\n")){
			printf("Write failed\n");
			return -1;
		}
		sleep(1);
	}

	return 0;
}