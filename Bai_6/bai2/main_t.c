#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pthread.h"
#include <string.h>

int ok[10] = {0,0,0,0,0,0,0,0,0,0};

void *func_create(void *var){
	FILE *fptr;
	char *path="test.txt";
	char filename[80];
	for(int i=0;i<10;i++){
		sprintf(filename,"%d%s",i,path);
		fptr = fopen(filename,"w");
		if(fptr==NULL)	pthread_exit(NULL);
		fclose(fptr);
		ok[i]=1;
		printf("%d\n", ok[i]);
	}
	pthread_exit(NULL);
}
void *func_random(void *var){
	char *path="test.txt";
	char filename[80];
	FILE *fptr;
	for(int i=0;i<10;i++){
		while(ok[i]==0);
		sprintf(filename,"%d%s",i,path);
		printf("%s\n", filename);
		while(access(filename, F_OK)!=0);
		fptr = fopen(filename,"a+");
		if(fptr==NULL)	pthread_exit(NULL);
		for(long j=0;j<5000000;j++){
			int num=(rand()%10);
			char num_str[2];
			sprintf(num_str,"%d",num);
			fwrite(num_str,1, strlen(num_str), fptr);
		}
		fclose(fptr);
	}
	pthread_exit(NULL);
}


int main(){
	pthread_t create,random;
	printf("Main\n");
	pthread_create(&create,NULL,func_create,NULL);
	pthread_create(&random,NULL,func_random,NULL);
	printf("Started\n");
	pthread_join(create,NULL);
	pthread_join(random,NULL);
	printf("End\n");
	return 0;
}