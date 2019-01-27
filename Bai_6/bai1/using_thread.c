#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"
typedef struct chanle{
	int chan,le;
}cl;

void *function(void *var){
	cl *cl_f = malloc(sizeof(cl));
	cl_f->le=cl_f->chan=0;
	long temp = *(int *)var;
	printf("%ld\n", temp);
	
	for(long i = (temp*1000000000);i<(1000000000+(temp*1000000000));i++) (i%2)?	cl_f->le++:cl_f->chan++;

	pthread_exit(cl_f);
}

int main(){
	pthread_t pthread_dem[10];
	cl *cl_m[10];
	long tong=0;

	for(int i=0;i<10;i++){
		pthread_create(&pthread_dem[i],NULL,function,(void *)&i);
		pthread_join(pthread_dem[i],(void **)&cl_m[i]);
	}

	for(int i=0;i<10;i++){
		tong = tong + cl_m[i]->le;
	}
	printf("%ld\n", tong);

	for(int i=0;i<10;i++)
		free(cl_m[i]);


	

	return 0;
}