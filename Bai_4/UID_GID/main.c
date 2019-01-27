#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int uid=1,uid_new=1;
	uid = getuid();
	printf("Current User ID: %d\n", uid);

	//changed uid to super id
	system("/usr/bin/id");
	uid_new = setuid(0);
	if(uid_new){
		printf("Cannot change UID to SU\n");
		return -1;
	}
	printf("Change to Super User: %d\n",getuid());

	int fc = open("test.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fc<0){
		printf("Cannot create \n");
		return -1;
	}
	printf("Create success file: %s\n", "test.txt");

	//change back to current uid
	system("/usr/bin/id");
	uid_new = setuid(uid);
	if(uid_new){
		printf("Cannot change back current user\n");
		return -1;
	}
	printf("Change back Current User\n");

	return 0;
}