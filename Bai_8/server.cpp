#include "stdio.h"
#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <string.h>
using namespace std;


int main(){
	cout<<"Chat with client";

	//connect to shared memory
	key_t shmkey = ftok("chat_on_pc",68);
	int shmid = shmget(shmkey, 1024, 0666|IPC_CREAT);
	char *str = shmat(shmid, (void *)0,0);
	while(1){
		char data[20];
		cout<<"Pleave input data send client\n";
		cin>>data;
		printf("%s\n", data);
		strcpy(str,data);
		while(!strcmp(str,data));
		printf("%s\n", str);
	}
}