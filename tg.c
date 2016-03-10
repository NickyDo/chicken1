#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
int importdb(FILE *fin, FILE *fout);
void printdata();
int importfromDB(FILE *f, int numLine);
void searchModel();
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
 
  FILE *f1;
  FILE *f2;
  int choice, i,n = 10, m = 10, p = 10;
  if(argc != 3) printf("try again\n");
  else if((f1 = fopen(argv[1], "rb")) == NULL) printf("something wrong\n");
  else if((f2 = fopen(argv[2],"wb")) == NULL) printf("Cannot open file");
  else{
    do{
      printf("1. Import DB from text\n");
      printf("2. Import from DB\n");
      printf("3. Print All Nokia Database\n");
      printf("4. Tim kiem dien thoai\n");
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
        printdata();
	break;
      case 4:  searchModel();
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
 void printdata(){
	int pagenum = 0;
	printf("\nData\n");
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
 }
int importfromDB(FILE *f, int numLine) {
	int result; // number of lines have been read
	int readMode; //readMode = 0 (all), = 1 (partially reading)

	int startFrom; //startFrom = 0 (begin), = 1 (end)
	int partNum; //number of line to read partially from beginning or end
	int position; //position where it begin to read

	do {
		printf("Choose 0 for read all data, 1 for read partially: ");
		scanf("%d", &readMode);
		if (readMode != 1 && readMode != 0)
			printf("Wrong choice of reading mode. Choose again\n");
	} while (readMode != 1 && readMode != 0);
	if (readMode == 0)
	{
		no = (nokia*)malloc(numLine * sizeof(nokia));
		result = fread(no, sizeof(nokia), numLine, f);
		printf("\nRead all data success\n");
		rewind(f);
	}
	else
	{
		do {
			printf("Choose 0 for read from beginning, 1 for from end: ");
			scanf("%d", &startFrom);
			if (startFrom != 1 && startFrom != 0)
				printf("Wrong choice of starting point. Choose again\n");
		} while (startFrom != 1 && startFrom != 0);



		printf("Input the position to start: ");
		scanf("%d", &position);
		do {
			printf("You want to read ? lines from the position: ");
			scanf("%d", &partNum);
			if (partNum <= 0)
				printf("Number of line must be positive\n");
		} while (partNum <= 0);

		no = (nokia*)malloc(sizeof(nokia) * partNum);
		if (startFrom == 0)
		{
			if (fseek(f, sizeof(nokia) * (position - 1), SEEK_SET) != 0)
				printf("Fseek failed!\n");
			else
				result = fread(no, sizeof(nokia), partNum, f);
			printf("\nRead from beginning success\n");
			rewind(f);
		}
		else
		{
			if (fseek(f, -sizeof(nokia) * position, SEEK_END) != 0)
				printf("Fseek failed!\n");
			else
				result = fread(no, sizeof(nokia), partNum, f);
			printf("\nRead from the end success\n");
			rewind(f);
		}
	}
	printf("\n");
	return result;
	free(no);
}
void searchModel() {
	char s[40];
	printf("\nSearch by phone model\n");
	printf("Type in the model\n");
	while (getchar() != '\n');
	scanf("%[^\n]", s);
	printf("\nSearch result: \n");
	for (int i = 0; i < result; ++i)
	  if (strstr(no[i].model, s) != NULL)
	    printf("%s\t%.2f\t%.2f\t%.2f\n", no[i].model, no[i].dungluong, no[i].kichthuoc, no[i].gia);
}
