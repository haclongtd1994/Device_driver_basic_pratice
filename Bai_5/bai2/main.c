#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signum){
	if(signum==2){
		printf("Exit while loop\n");
	}
}

int main(){
	char data[100];
	signal(2,signal_handler);
	scanf("%s",data);
	pause();
	printf("Comment from main exit program with data: %s\n",data);
	return 0;
}