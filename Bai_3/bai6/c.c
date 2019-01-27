#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int main(){
	pid_t pid = getpid();
	pid_t sid = getsid(pid);

	printf("%d\n", sid);
	return 0;
}