#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <string.h>
#define max 100
typedef struct{
  int stt, mssv;
  char hoten[max], sdt[max];
  float diem;
} hocsinh;

void main(int argc, char* argv[]){
  FILE* f1;
  FILE* f2;
  hocsinh *st;
  int n, i = 0;
  if(argc != 4){
    printf("somthing wrong in here! please comeback later\n"); 
  }
  else
    if((f1 = fopen(argv[1], "rb")) == NULL){
      printf("Can't open this file\n");
    }
    else
      if((f2 = fopen(argv[2], "wb")) == NULL){
        printf("Can't open this file\n");
      }
      else{
	n = atoi(argv[3]);
	st = (hocsinh*)malloc(n * sizeof(hocsinh));
        
	for(i = 0; i < n; i++){
	  fscanf(f1, "%d\t", &st[i].stt);
	  fscanf(f1,"%d\t",&st[i].mssv);
	  fscanf(f1, "%[^\t]\t%[^\n]",st[i].hoten, st[i].sdt);
	  printf("Input score of student %d-order:", i + 1);
	  scanf("%f", &st[i].diem);
	} //order to put information of score's student
	for(i = 0; i < n; i++){
	  fprintf(f2, "%d\t%d\t%s\t%s\t%.2f\n", st[i].stt, st[i].mssv, st[i].hoten, st[i].sdt, st[i].diem);
	}
	fclose(f1);
	fclose(f2);
      }
  free(st);
}
