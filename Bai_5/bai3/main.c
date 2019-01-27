#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

char status[126];

void signal_handler(int signum){
	if(signum==SIGINT){
		printf("Status Ctrl+C: %s\n", status);
	}
}

int main(int argc, char *argv[]){
	sigset_t set,set_r;
	signal(SIGINT,signal_handler);

	while(1){
		printf("What do you want? unset or block\n");
		scanf("%s",status);
		if(!strcmp(status,"unset")){
			if(sigprocmask(SIG_UNBLOCK,&set,&set_r)<0){
				printf("Cannot unblock SIGINT\n");
				return -2;
			}
			sigdelset(&set,SIGINT);
		}
		else if(!strcmp(status,"block")){
			sigaddset(&set,SIGINT);
			if(sigprocmask(SIG_BLOCK,&set,&set_r)<0){
				printf("Cannot block SIGINT\n");
				return -2;
			}
		}
	}
	return 0;
}