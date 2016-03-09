#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 20

typedef struct{
  char ten[max];
  int so;
}danhba;

void main(int argc, char *argv[]){
  danhba *db;
  FILE *f1;
  FILE *f2;
  FILE *f3;
  int i, n;
  if(argc != 5) printf("something wrong\n");
  
  else if((f1 = fopen(argv[1], "rb")) == NULL) printf("Can't open this file\n");
  else if((f2 = fopen(argv[3], "wb")) == NULL) printf("Can't open this file\n");
  else if((f3 = fopen(argv[4], "wb")) == NULL) printf("Can't open this file\n");
  else{
    n = atoi(argv[2]);
    db = (danhba*)malloc(n* sizeof(danhba));
    for(i = 0; i < 100; i++){
      fscanf(f1, "%[^\t]\t", db[i].ten);
      fscanf(f1, "%d\n", &db[i].so);
    }
    for(i = 0; i < n; i++){
      fprintf(f2, "%s\t%d\n", db[i].ten, db[i].so);
    }
    for(i = n; i < max; i++){
      fprintf(f3, "%s\t%d\n", db[i].ten, db[i].so);
    }
    
  }
  free(db);
  fclose(f1);
  fclose(f2);
  fclose(f3);
}
