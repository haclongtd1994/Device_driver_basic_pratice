#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/stat.h"
#include "string.h"
#include "fcntl.h"

int main(){
	int fd;
	struct stat pstat;
	char *folder1 = "TestFolder";
	char *folder2 = "/Test1";
	char *file1 = "/efg";
	char *file2 = "/abc";

	char *data = malloc(strlen(folder1) + (strlen(file1)>strlen(folder2))? strlen(file1):strlen(folder2) + strlen(file2) +2);
	char *data2 = malloc(strlen(folder1) + (strlen(file1)>strlen(folder2))? strlen(file1):strlen(folder2) + strlen(file2) +2);
	char *PATH = malloc(strlen(folder1) + (strlen(file1)>strlen(folder2))? strlen(file1):strlen(folder2) + strlen(file2) +2);

	PATH = strcpy(PATH,folder1);
	//make folder 1
	printf("Make a folder 1: %s\n", PATH);
	fd = mkdir(PATH, 0664);
	if(fd<0){
		printf("cannot creat or open path: %s\n",PATH );
		return -1;
	}


	PATH = strcat(PATH, file1);
	//create file 1(check) and create folder 2
	fd = open(PATH,O_CREAT,0664);
	if(fd<0){
		printf("cannot creat file 1: %s\n",PATH );
		return -1;
	}
	//check readonly if true tranfer to buffer
	if(stat(PATH,&pstat)<0){
		printf("cannot check permission path: %s\n",PATH );
		return -2;
	}
	printf("PSTAT FILE 1: %s      MODE: %o	CHECK: %o\n",PATH, pstat.st_mode, (S_IFREG|S_IRUSR|S_IRGRP|S_IROTH));
	(pstat.st_mode==(S_IFREG|S_IRUSR|S_IRGRP|S_IROTH))?  strcpy(data,PATH):strcpy(data,"Khong phai\n") ;
	close(fd);

	//create folder 2
	PATH = strcpy(PATH, folder1);
	PATH = strcat(PATH, folder2);
	fd = mkdir (PATH,0664);
	if(fd<0){
		printf("cannot creat or open path: %s\n",PATH );
		return -1;
	}


	PATH = strcat(PATH,file2);
	fd = open(PATH,O_CREAT,0444);
	if(fd<0){
		printf("cannot creat file2: %s\n",PATH );
		return -1;
	}

	if(stat(PATH,&pstat)<0){
		printf("cannot check permission path: %s\n",PATH );
		return -2;
	}
	printf("PSTAT FILE 2: %s      MODE: %o	CHECK: %o\n", PATH,pstat.st_mode,(S_IFREG|S_IRUSR|S_IRGRP|S_IROTH));
	(pstat.st_mode==(S_IFREG|S_IRUSR|S_IRGRP|S_IROTH))?  strcpy(data2,PATH):strcpy(data2,"Khong phai\n") ;

	close(fd);

	printf("File 1 read only ? is: %s\n", data);
	printf("File 2 read only ? is: %s\n", data2);

	return 0;

}