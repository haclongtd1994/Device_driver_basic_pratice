#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signum){
	if(signum==SIGINT){
		printf("User cannot Ctrl+C\n");
	}
}
int main(){
	signal(SIGINT,signal_handler);
	while(1);
}