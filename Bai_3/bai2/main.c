#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("ATTR: FILE <pathname>\n");
		return -1;
	}
	FILE *fptr = fopen(argv[1],"r");
	if(fptr==NULL){
		printf("Cannot access to file: %s\n", argv[1]);
		return -1;
	}

	return 0;
}