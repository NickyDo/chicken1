#include "stack.h"
void he2(int so);
void he16(int so);
void main(){
  int choice, so;
  
  do{
    printf("1. Chuyen tu he 10 sang he 2 \n");
    printf("2. Chuyen tu he 10 sang he 16 \n");
    printf("3. Thoat\n");
    scanf("%d", &choice);
    switch(choice){
    case 1:
      he2(so);
      break;
    case 2: he16(so);
      break;
    case 3: break;
    default:printf("something wrong\n");
    }
  }while(choice != 3);
}

void he2(int so){
int coso, du;
  char d, ketqua;
  stack_type *p;
  
  p = (stack_type *)malloc(sizeof(stack_type));
  initialize(p);
  printf("Nhap so muon chuyen:\n");
  scanf("%d", &so);

  while(so != 0){
    du = so % 2;
    so = so / 2;
    d = du + '0';
    push(d, p);
  } 
  printf("Ket qua:\n");
  while(ketqua = pop(p)){ 
    printf("%c", ketqua);
  }
  printf("\n");
}

void he16(int so){
int coso, du;
  char d, ketqua;
  stack_type *p;
  
  p = (stack_type *)malloc(sizeof(stack_type));
  initialize(p);
  printf("Nhap so muon chuyen:\n");
  scanf("%d", &so);

  while(so != 0){
    du = so % 16;
    so = so / 16;
    d = du + '0';
    if(du == 10) d = 'A';
    else if(du == 11) d = 'B';
    else if(du == 12) d = 'C';
    else if(du == 13) d = 'D';
    else if(du == 14) d = 'E';
    else if(du == 15) d = 'F';
    else d = du + '0';
    push(d, p);
  } 
  printf("Ket qua:\n");
  while(ketqua = pop(p)){ 
    printf("%c", ketqua);
  }
  printf("\n");
}
