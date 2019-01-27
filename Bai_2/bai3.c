#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "string.h"
#include "sys/stat.h"

int main(){
	int fd,fr;
	char data[64];
	memset(data,0,64);
	char *FILE="/dev/my_misc_device";

	fd = open(FILE,O_RDONLY);
	if(fd<0){
		printf("cannot open device file\n");
		return -1;
	}

		fr =(int )read(fd,data,1024);
		printf("%s\n", data);
	

}