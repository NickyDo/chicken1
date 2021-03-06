#include "bst.h"

int main() {
  TNode *root = NULL;  // Creating an empty tree
  /*Code to test the logic*/
//             15
//	      /  \
//           10	  20
//          / \   / \
//	   8  12 21 25
//        /
//       
  root = Insert(root, 15);	
  root = Insert(root, 10);	
  root = Insert(root, 20);
  root = Insert(root, 25);
  root = Insert(root, 8);
  root = Insert(root, 12);
  root = Insert(root, 21);
 

  // Ask user to enter a number.  

  /*int number;
  printf("Enter number be searched\n");
  scanf("%d", &number);
  //If number is found, print "FOUND"
  if(Search(root,number) == 1) printf("Found %d\n");
  else printf("Not Found\n");
  */
  printf("height if tree is: %d\n", findHeight(root));
  printf("Number of leaf: %d\n", numberofleaf(root));
  printf("Number of Node: %d\n", countNode(root));
  printf("Number of rightchild: %d\n", countrightchild(root));
  printf("Number of internal nodes: %d\n", countNode(root)-numberofleaf(root));
  preorder(root);
  printf("\n");
  inorder(root);
  printf("\n");
  postorder(root);
  printf("\n");
  // breadth_fist(root);
  printf("Min element is %d\n", FindMin(root));
  printf("Max element is %d\n", FindMax(root));
  //if(IsBinarySearchTree(root)) printf("It's BST\n");
 
  /*
    reverseTree(root);
    printf("After reverse tree:\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
  */
  // DeleteMin(&root);
  DeleteNode(12, &root);
  //Delete(root, 12);
  inorder(root);
  printf("\n");
  
}	   
