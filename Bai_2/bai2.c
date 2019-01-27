#include "dirent.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "sys/stat.h"
#include "time.h"

int main(){
	DIR *fdir;
	char FNAME[]="FOLDER_BAI_2";
	char PATHNAME[1024];
	char buff[1024];
	struct dirent *dp;
	struct stat pstat;

	fdir = opendir(FNAME);
	if(fdir==NULL){
		printf("Open folder error\n");
		return -1;
	}
	while((dp = readdir(fdir))!=NULL){
		sprintf(PATHNAME,"FOLDER_BAI_2/%s", dp->d_name);

		memset(&pstat, 0, sizeof(pstat));
		if(stat(PATHNAME, &pstat)<0){
			
			printf("Cannot search info file\n");
			return -2;
		}
		else{
			if ((pstat.st_mode & S_IFDIR) == S_IFDIR) continue;
			printf("%s:  ", dp->d_name);
			printf("Size: %u,  ",(unsigned int)pstat.st_uid);
			strftime(buff, sizeof buff, "%D %T", gmtime(&pstat.st_mtim.tv_sec));
			printf("Modify time: %s        %ld\n",buff,pstat.st_mtim.tv_sec);
		}
	}
	
	
}
/*
int main(){
	struct stat pstat;

		if(stat("FOLDER_BAI_2/main", &pstat)<0){
			
			printf("Cannot search info file\n");
			return -2;
		}
		else{
			printf("%u\n",(unsigned int)pstat.st_uid);
			printf("%u\n",(unsigned int)pstat.st_gid);
			printf("%u\n",(unsigned int)pstat.st_size);
		}
	
}
*/