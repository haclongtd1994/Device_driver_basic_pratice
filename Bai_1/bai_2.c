#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]){
	FILE *fptr;
	char c;
	if(argc !=2){
		printf("Arggrument is: file <pathname>\n");
		return -1;
	}
	else{

		fptr = fopen(argv[1],"r");
		if(fptr==NULL){
			printf("Cannot find file\n");
			return -1;
		}
		c = fgetc(fptr);
		while(c != EOF){
			printf("%c", c);
			c = fgetc(fptr);
		}
		printf("\n");
		return 0;
	}
	

}