#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
int importdb(FILE *fin, FILE *fout);
int importfromDB(FILE *fptr, int num);

typedef struct{
  char model[max];
  float dungluong;
  float kichthuoc;
  float gia;
}nokia;
nokia *no;
int result;

void main(int argc, char*argv[]){
  int numline;
  char s[max];
  FILE *f1;
  FILE *f2;
  int choice, i, pagenum = 0, n = 10, m = 10, p = 10;
  
  if(argc != 3) printf("try again\n");
  else if((f1 = fopen(argv[1], "r")) == NULL) printf("something wrong\n");
  else if((f2 = fopen(argv[2],"w+")) == NULL) printf("Cannot open file");
  else{
    do{
      printf("1. Import DB from text\n");
      printf("2. Import from DB\n");
      printf("3. Print All Nokia Database\n");
      printf("4. Tim kiem dien thoai: Theo Model\n");
      printf("5. Exit\n");
      scanf("%d", &choice);
      switch(choice){
      case 1:
	if((f1 = fopen(argv[1], "rb")) == NULL) printf("something wrong\n");
	if((f2 = fopen(argv[2],"wb")) == NULL) printf("Cannot open file\n");
  
	numline = importdb(f1, f2);
	fclose(f1);
	fclose(f2);
	break;
      case 2:
	if((f2 = fopen(argv[2],"rb")) == NULL) printf("Cannot open file\n");
	result = importfromDB(f2, numline);
	fclose(f2);
	break;
      case 3:
	if(result < 20)
	  for(int i = 0; i < result; ++i)
	    	  printf("%s\t%.2f\t%.2f\t%.2f\n", no[i].model, no[i].dungluong, no[i].kichthuoc, no[i].gia);
	else{
	  int curnum;
	  do{
	    curnum = 20 + 20*pagenum;
	    if(curnum >= result)
	      curnum = result;
	    printf("\n\npage number %d\n\n", pagenum + 1);
	    for(int i = pagenum * 20; i < curnum; ++i)
	      	  printf("%s\t%.2f\t%.2f\t%.2f\n", no[i].model, no[i].dungluong, no[i].kichthuoc, no[i].gia);
	    pagenum++;
	  }while(curnum < result);
	}
 
	break;
      case 4:   
	printf("Nhap model:\n");
	while (getchar() != '\n');
	scanf("%[^\n]", s);
	printf("\nKet qua tra cuu: \n");
	for (int i = 0; i < result; ++i)
	  if (strstr(no[i].model, s) != NULL)
	    printf("%s\t%.2f\t%.2f\t%.2f\n", no[i].model, no[i].dungluong, no[i].kichthuoc, no[i].gia);
	break;
      case 5:
	break;
      default: printf("ERROR\n");
      }
    }while(choice != 5);
  }
	
}
int importdb(FILE *fin, FILE *fout){
  int i = 0;
  int numline = 0;
  char line[10000];
  while(fgets(line,10000, fin) != NULL)
    numline++;
  rewind(fin);
  no = (nokia*)malloc(numline*sizeof(nokia));
  for(i = 0; i < numline; i++){
    fscanf(fin, "%[^\t]\t", no[i].model);
    fscanf(fin, "%f\t%f\t%f\n", &no[i].dungluong, &no[i].kichthuoc, &no[i].gia);
  }
  return fwrite(no, sizeof(nokia), numline, fout);
}

int importfromDB(FILE *fptr, int num) {
	int result; // number of lines have been read
	int readMode; //readMode = 0 (all), = 1 (partially reading)

	int startFrom; //startFrom = 0 (begin), = 1 (end)
	int partNum; //number of line to read partially from beginning or end
	int position; //position where it begin to read

	do {
		printf("Nhan phim 0 de doc toan bo file, nhan phim 1 de doc theo yeu cau:");
		scanf("%d", &readMode);
		if (readMode != 1 && readMode != 0)
			printf("Nhap lai\n");
	} while (readMode != 1 && readMode != 0);
	if (readMode == 0)
	{
		no = (nokia*)malloc(num * sizeof(nokia));
		result = fread(no, sizeof(nokia), num, fptr);
		printf("Oki! Da doc xong! Bay h quay ra roi chon tiep nhe ^^\n");
		rewind(fptr);
	}
	else
	{
		do {
			printf("Nhan 0 de doc tu diem khoi dau, 1 de doc tu cuoi len: ");
			scanf("%d", &startFrom);
			if (startFrom != 1 && startFrom != 0)
				printf("Nhap lai:\n");
		} while (startFrom != 1 && startFrom != 0);

		printf("bat dau tu vi tri:");
		scanf("%d", &position);
		do {
			printf("so phan tu muon doc:");
			scanf("%d", &partNum);
			if (partNum <= 0)
				printf("Khong nhan so am\n");
		} while (partNum <= 0);

		no = (nokia*)malloc(sizeof(nokia) * partNum);
		if (startFrom == 0)
		{
			if (fseek(fptr, sizeof(nokia) * (position - 1), SEEK_SET) != 0)
				printf("Fseek failed!\n");
			else
				result = fread(no, sizeof(nokia), partNum, fptr);
		        
			rewind(fptr);
		}
		else
		{
			if (fseek(fptr, -sizeof(nokia) * position, SEEK_END) != 0)
				printf("Fseek failed!\n");
			else
				result = fread(no, sizeof(nokia), partNum, fptr);
	        
			rewind(fptr);
		}
	}
	printf("\n");
	return result;
	free(no);
}
