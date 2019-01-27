#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

char data[100];

sigset_t set;
int space=0;

void check_process_data(){

	if(space != 1){
		printf("Aguda: <COMMAND> <SIGnals> %d\n",space);
	}
	char *token = strtok(data," ");
	int signals[32],k=0;

	if(token==NULL){
		printf("Strtok space failed\n");
	}
	else{
		printf("%s\n", token);
		if(!strcmp(token,"add")){
			token = strtok(NULL,",");
			//signals[k] = atoi(token);
			printf("%d\n", atoi(token));
			while(token!=NULL){
				token = strtok(NULL,",");
				//signals[k] = atoi(token);
				printf("%d\n", atoi(token));
				k++;
			}
			for(int j=0;j<k;j++){
				sigaddset(&set,signals[j]);
			}
			printf("Add:\n");
			for(int j=0;j<32;j++){
				if(sigismember(&set,j))	printf("%d\n", j);
			}
		}
		else if(!strcmp(token,"del")){
			do{
				token = strtok(NULL,",");
				signals[k] = atoi(token);
				k++;
			}while(token!=NULL);
			for(int j=0;j<k;j++){
				sigdelset(&set,signals[j]);
			}
			printf("Del:\n");
			for(int j=0;j<32;j++){
				if(!sigismember(&set,j))	printf("%d\n", j);
			}
		}
	}
}

int main(){
	printf("Type data with format: <COMMAND> <SIGnals>\n");
	scanf("%[^\n]s",data);
	
	for(int i=0;data[i]!='\0';i++){
		if(data[i]==' '){
			space++;
		}
	}
	printf("%s with %d\n", data,space);
	check_process_data();

	return 0;
}