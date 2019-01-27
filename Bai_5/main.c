#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signum){
	if(signum==SIGINT){
		printf("Signal 1\n");
	}
}
void signal_handler_buffer(int signum){
	if(signum==12){
		printf("Signal 2\n");
	}
}

int main(){
	sigset_t set,set_r;

	sigaddset(&set,2);
	sigaddset(&set,12);

	signal(2,signal_handler);
	signal(3,signal_handler_buffer);

	if(sigismember(&set,2)&&sigismember(&set,12))	printf("signal 2,3 success\n");

	sigprocmask(SIG_BLOCK, &set, &set_r);
	while(1){
		if(sigpending(&set)<0){
			printf("Cannot take pending\n");
			return -1;
		}
		if(sigismember(&set,12)){
			sigprocmask(SIG_UNBLOCK, &set, &set_r);
		}
	}
}