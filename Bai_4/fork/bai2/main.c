#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"

int main(){
	size_t kt;
	char parent[64] = "I am parent";
	char child[64]	= "I am child";
	FILE *fptr = fopen("test.txt","w");
	if(fptr==NULL){
		printf("Cannot open file pleave create or check\n");
		return -1;
	}
	
	
	pid_t pid = fork();
	if(pid!=0){
		kt = fwrite(&parent,1,strlen(parent),fptr);
		if(kt!=strlen(parent)){
			printf("failed to write from parent\n");
			return -2;
		}
		else printf("%s\n", parent);
		fclose(fptr);
		return 0;
	}
	else{
		kt = fwrite(&child,1,strlen(child),fptr);
		if(kt!=strlen(child)){
			printf("failed to write from child\n");
			return -2;
		}
		else printf("%s\n", child);
		fclose(fptr);
		return 0;
	}
	
}