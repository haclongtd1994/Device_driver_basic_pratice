#include <stdio.h>
#include <stdlib.h>

int main(){
	long le=0;
	for(long sd=1;sd<=10000000000;sd++){
		if((sd%2)!=0)	le++;
	}

	printf("%zd: %ld\n", sizeof(le),le);
	return 0;
}