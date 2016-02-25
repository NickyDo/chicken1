#include<stdio.h>
#include<stdlib.h>
#define max 100

void charrw(FILE*fin);
void main(int argc, char* argv[]){
  int i;
  FILE *f1;
  FILE *f2;
  FILE *f3;
  
  if(argc != 2 && argc != 3 && argc != 4){ printf("something not right\n");
    }
    else{
      if(argc == 2){
	if((f1 = fopen(argv[1] , "r")) == NULL)
	  printf("cannot open this file\n");
	else{
	  charrw(f1);
	  fclose(f1);
	}
      }
      else if(argc == 3){
	if((f1 = fopen(argv[1] , "r")) == NULL)
	  printf("cannot open thisfile\n");
	else if((f2 = fopen(argv[2], "r")) ==NULL)
	  printf("cannot open thisfile\n");
	else{
	  charrw(f1);
	  charrw(f2);
	  fclose(f1);
	  fclose(f2);
	}
      }
      else if(argc == 4){
	if((f1 = fopen(argv[1] , "r")) == NULL)
	  printf("cannot open thisfile\n");
	else if((f2 = fopen(argv[2], "r")) ==NULL)
	  printf("cannot open thisfile\n");
	else if((f3 = fopen(argv[3], "r")) ==NULL)
	  printf("cannot open thisfile\n");
	else{
	  charrw(f1);
	  charrw(f2);
	  charrw(f3);
	  fclose(f1);
	  fclose(f2);
	  fclose(f3);
	}
      }
      else ;
    }
}

void charrw(FILE*fin){
  int num;
  char buff[max +1];
  while(!feof(fin)){
    num = fread(buff,sizeof(char), max, fin);
    buff[num*sizeof(char)] = '\0';
    printf("%s", buff);
  }
}
  
