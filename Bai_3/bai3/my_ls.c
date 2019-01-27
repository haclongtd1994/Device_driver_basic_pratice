#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"

int no_attr(){
	printf("normal mt_ls\n");
	return 1;
}
int one_attr(char data[]){
	if(!strcmp(data,"-a")){
		printf("Hien thi file an\n");
		return 1;
	}
	else if(!strcmp(data,"-l")){
		printf("full property\n");
		return 1;
	}
	else if(!strcmp(data,"-la")){
		printf("Hien thi file an va full property\n");
		return 1;
	}
	else{
		printf("OPtion: -l -a -la\n");
		return 0;
	}
}

int main(int argc, char *argv[]){
	if(argc==1){
		if(no_attr())	return 0;
	}
	else if(argc==2){
		if(one_attr(argv[1]))	return 0;
		else			return -1;
	}
	else{
		printf("ATTR: FILE <option>\n");
		return -1;
	}	
}