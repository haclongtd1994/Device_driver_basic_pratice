#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Arrgrument failed: intrustion <file_name>\n");
		return -1;
	}
	else{
		FILE *fptr;
		char c;

		fptr = fopen(argv[1],"r");
		if(fptr==NULL){
			printf("Cannot open file\n");
			return -2;
		}

		c = fgetc(fptr);
		while(c!=EOF){
			printf("%c",c);
			c = fgetc(fptr);
		}
		return 0;
	}
}