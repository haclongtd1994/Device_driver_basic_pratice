#include <stdio.h>
#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <string.h>

int main(){
	key_t shmkey = ftok("shmfile",90);
	int shmid = shmget(shmkey, 1024, 0666|IPC_CREAT);
	char *str = shmat(shmid, (void *)0, 0);
	printf("Data of memory shared: %s\n", str);
	shmdt(str);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}