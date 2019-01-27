#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int main(){
	pid_t pid=getpid();
	pid_t pgid = getpgid(pid);

	sleep(10);

	printf("%d\n", pgid);

	return 0;
}