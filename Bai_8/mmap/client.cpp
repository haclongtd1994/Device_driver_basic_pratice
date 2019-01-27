#include "stdio.h"
#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <sys/types.h>
#include <unistd.h>

using namespace std;
void signal_handler(int signum){
	if(signum==2){
		printf("Exit while loop\n");
	}
}
int main(){
	const char* name = "Chat.txt";
	int shm_fd = open(name,O_CREAT|O_RDWR,0666);
	if(shm_fd<0){
		perror("Cannot open file");
		return -EACCES;
	}
  	lseek(shm_fd, 1023, SEEK_SET);
	write(shm_fd, "", 1);
	char *str = mmap(0, 1024, PROT_WRITE|PROT_READ, MAP_SHARED, shm_fd, 0);
	char data[50];
	while(1){
		cout<<"Chat with server\n"<<"Max data length: 50\n"<<"Type input:\n";
		cin>>data;
		memcpy(str,data, strlen(data));
		printf("%d :  %s\n",strlen(str), str);
		str += 50;
		while(*str=='\0');
		printf("%s\n", str);
		str += 50;
	}
}