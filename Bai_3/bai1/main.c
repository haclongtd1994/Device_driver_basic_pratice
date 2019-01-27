#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

extern void info_success();

int main(int argc, char *argv[]){
	FILE *fptr;

	if(argc!=2){
		printf("ATTR: FILE <pathname>\n");
		return -2;
	}
	printf("Logging file %s\n", argv[1]);

	fptr = fopen(argv[1],"r");
	if(fptr==NULL){
		printf("Cannot open file\n");
		return -1;
	}

	info_success();

	return 0;

}