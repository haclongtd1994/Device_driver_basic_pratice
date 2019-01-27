#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void check_line(char *line){
	char *token;
	int i=0,ok=0;

	token = strtok(line," ");
	while((token!=NULL)&&(i<2)){
		i++;
		if(ok==1){
			printf("%s\n", token);
		}
		else{
			if(!strcmp(token,"echo")) ok=1;
			else{
				ok=0;
			}
		}
		token = strtok(NULL,"\"");
	}
	
}
int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Aguda1: <Command> <ATTR>\n");
		return -1;
	}
	printf("argc: %d, argv: %s %s, ENV(PWD): %s \n",argc , argv[0], argv[1], getenv("PWD"));
	//Tach filename can thiet
	char *temp;
	char *filename = argv[1];
	temp = strtok(filename,"/");
	while(temp!=NULL){
		filename = temp;
		temp = strtok(NULL,"/");
	}
	printf("%s\n", filename);
	//Ghep tao file pathname
	char pathname[1024];
	snprintf(pathname, 1024, "%s/%s",getenv("PWD"),filename);
	printf("%s\n", pathname);
	//open file .sh to process
	FILE *fptr = fopen(pathname,"r");
	if(fptr==NULL){
		printf("Cannot open file with path name: %s\n", pathname);
		return -1;
	}
	char data[1024];
	size_t len = 255;
	char *line = malloc(sizeof(char) * len);

	while(fgets(line, len, fptr) != NULL) {
        check_line(line);
    }
	free(line);

    fclose(fptr);


	return 0;
}



