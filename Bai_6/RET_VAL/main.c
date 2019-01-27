#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct cho{
	char name[50];
	int tuoi;
}sinhvien;

void *function_thread(void *var){
	sinhvien *sv = malloc(sizeof(sinhvien));

	printf("NAME: ");
	scanf("%s",sv->name);
	printf("AGE: ");
	scanf("%d",&(sv->tuoi));

	pthread_exit(sv);
}
int main(){
	sinhvien *sv;
	printf("Nhap vao ten va tuoi:\n");
	pthread_t pthread_input;
	pthread_create(&pthread_input, NULL, function_thread, NULL);
	pthread_join(pthread_input,(void **)&sv);

	printf("Name: %s, Age: %d\n", sv->name, sv->tuoi);
	free(sv);
	return 0;
}