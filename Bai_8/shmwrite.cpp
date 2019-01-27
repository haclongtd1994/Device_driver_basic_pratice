#include "stdio.h"
#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <string.h>
using namespace std;


int main(int argc, char * argv[]){
	if(argc!=2){
		perror("Agenda: Filec++ string_want_to_write\n");
		return -1;
	}
	key_t shmkey = ftok("shmfile",90);
	int shmid = shmget(shmkey, 1024, 0666|IPC_CREAT);
	char *str = shmat(shmid, (void *)0, 0);
	cout<<"Pleave insert data to memory shared shm: ";
	strcpy(str,argv[1]);
	printf("Data insert to memory share shm: %s\n", str);
	shmdt(str);
	return 0;
}

