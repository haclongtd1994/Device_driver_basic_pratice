#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
	int fd,fs,offset;
	char data[64];
	if(argc!=3){
		printf("Check arrgrument: ./bai1 <FILENAME> <PositionWantRead>\n");
		return -2;
	}
	fd = open(argv[1],O_RDONLY);
	if(fd<0){
		printf("Cannot open file name: %s\n", argv[1]);
		return -1;
	}

	offset = atoi(argv[2]);	//convert char to interger
	if(offset<0){
		printf("Position failed\n");
		return -1;
	}
	fs = (int) lseek(fd,offset,SEEK_SET);
	if(fs==offset){
		printf("fs and offset current: %d\n", fs);
	}
	while(1){
		fs = read(fd,data,64);
		if(fs>0){
			data[fs]=0;
			printf("%s\n", data);
		}
		else{
			printf("\n");return 0;
		}
		return 0;
	}
}