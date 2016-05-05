#include "bst.h"
#define max 100

void main(int argc, char *argv[]){
  FILE *f1;
  int i, choice;
  //  element index[max];
  tree_type root;
  makeNullTree(&root);
  element_type tumuonthem;
  char tucantim[max];
  char tu[max];
  char nghia[max];
  char tucanxoa[max];
  
  if(argc != 2) printf("something wrong\n");
  else{
    if((f1 = fopen(argv[1], "w+")) == NULL) printf("can't open this file\n");
    else{
      do{
	printf("1. Tim kiem\n");
	printf("2. Them tu\n");
	printf("3. Xoa tu\n");
	printf("4. Ghi du lieu vao file\n");
	printf("5. Thoat\n");
	scanf("%d", &choice);
	switch(choice){
	case 1:
	  while(getchar() != '\n');
	  printf("Dien tu can tim:\n");
	  scanf("%[^\n]", tucantim);
	  printf("Ketqua:\n");
	  search(root, tucantim);	  
	  break;
	case 2:
	  while(getchar() != '\n');
	  printf("Nhap tu muon them:\n");
	  scanf("%[^\n]", tumuonthem.tu);
	  // printf("%s\n", tumuonthem.tu);
	  while(getchar() != '\n');
	  printf("NHap nghia cua tu do:\n");
	  scanf("%[^\n]", tumuonthem.nghia);
	  //printf("%s\n", tumuonthem.nghia);
	  insert(&root, tumuonthem);
	  //inorder(root);
	  break;
	case 3:
	  printf("NHap tu muon xoa:\n");
	  scanf(" %[^\n]", tucanxoa);
	  delete(&root, tucanxoa);
	  //inorder(root);
	  break;
	case 4:
	  fprintf(f1, "%s: %s\n", root->info.tu, root->info.nghia);
	  fclose(f1);
	  //freeTree(root);
	  break;
	case 5: printf("Ending...\n");
	  break;
	default: printf("ERROR\n");
	}
      }while(choice != 5);
    }
  }
}


