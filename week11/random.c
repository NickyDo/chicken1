#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bst.h"

tree_type root;
void main(){
 
  int so, i, choice, number;
    
      do{
	printf("1. Tao bo so lieu va tao cay\n");
	printf("2. freeTree\n");
	printf("3. In ra so phep so sanh\n");
	printf("4. Tim kiem\n");
	printf("5. exit\n");
	scanf("%d", &choice);
	switch(choice){
	case 1:
	  //srand(time(NULL));
	  for(i = 0; i < 1000000; i++){
	    
	    so = rand()%1000001;
	    insert(&root, so);
	    // printf("%d\n", so);
	  }
	 
	  //preorder(root);
	  // printf("\n");
	 
	  break;
	case 2:
	  freeTree(root);
	  break;
	case 3:
	  inorder(root);
	  printf("number of comparision: %d\n", height(root));
	  
	  break;
	case 4:
	  printf("Enter your number be search:\n");
	  scanf("%d", &number);
	  if(search(root, number) == NULL) printf("Not Found\n");
	  else printf("Found\n");
	  break;
	case 5:
	  //free(root);
	  break;
	default: printf("Error\n");
	}
      }while(choice != 5);
}
    




