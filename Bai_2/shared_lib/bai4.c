#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"


_Bool copy_file(){
  FILE *des,*sour;
  char data;
  int pos;
  sour = fopen("libfoo.so","r");
  if(sour==NULL){
    printf("Failed to open source file libfoo: %s\n", "libfoo.so");
    return 0;
  }
  des = fopen("/usr/bin/libfoo.so","w");
  if(des==NULL){
    printf("Failed to open des file libfoo to copy: %s\n", "libfoo(copy).so");
    return 0;
  }
  fseek(sour,0L,SEEK_END);
  pos = ftell(sour);
  fseek(sour,0L,SEEK_SET);
  while(pos--){
    data = fgetc(sour);
    fputc(data,des);
  }
  printf("Copy file successfull\n");
  fclose(sour);
  fclose(des);
  return 1;
}

_Bool copy_file_2(){
  FILE *des,*sour;
  char data;
  int pos;
  sour = fopen("test","r");
  if(sour==NULL){
    printf("Failed to open source file libfoo: %s\n", "libfoo.so");
    return 0;
  }
  des = fopen("test_2","w");
  if(des==NULL){
    printf("Failed to open des file libfoo to copy: %s\n", "libfoo(copy).so");
    return 0;
  }
  fseek(sour,0L,SEEK_END);
  pos = ftell(sour);
  fseek(sour,0L,SEEK_SET);
  while(pos--){
    data = fgetc(sour);
    fputc(data,des);
  }
  printf("Copy file successfull\n");
  fclose(sour);
  fclose(des);
  return 1;
}

int main(){
  char *data_check;
  //STEP 1: Create a file in folder(/etc/foo.conf)
  FILE *fptr;
  fptr = fopen("test", "rb+");
  if(fptr == NULL) //if file does not exist, create it
  {
      fptr = fopen("test_2", "w+");
  }
  fclose(fptr);

  //STEP 2:coppy lib to /usr/bin
  (copy_file())?  strcpy(data_check,"Step 2 OK"):strcpy(data_check,"Step 2 failed");
  printf("%s\n", data_check);

  (copy_file_2())?  strcpy(data_check,"Step 3 OK"):strcpy(data_check,"Step 3 failed");
  printf("%s\n", data_check);

  return 0;
}
