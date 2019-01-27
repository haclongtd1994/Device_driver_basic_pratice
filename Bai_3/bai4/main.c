#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

extern char **environ;

int main(){
	char *data;

	data = getenv("HOME");
	printf("HOME: %s\n", data);

	data = getenv("USER");
	printf("USER: %s\n",data);

	data = getenv("PWD");
	printf("PWD: %s\n", data);

	return 0;
}