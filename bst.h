#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(x , y) do { typeof(x) SWAP = (x); (x) = (y) ; (y) =SWAP;} while (0);
#define max 100
typedef struct{
  char tu[max];
  char nghia[max];
} element;

typedef struct Node Node;
struct Node{
  element data;
  Node *left;
  Node *right;
};

Node* GetNewNode(element data){
  Node *NewNode = (Node *)malloc(sizeof(Node));
  NewNode->data = data;
  NewNode->left = NULL;
  NewNode->right = NULL;
  return NewNode;
}

int emptyTree(Node* root) {
	return root == NULL;
}

void freeTree(Node* root) {
	if (emptyTree(root))
		return;
	freeTree(root->left);
	freeTree(root->right);
	free(root);
	return;
}

void Insert(Node *root,  element data){
  int index = 0;
  index = strcmp(root->data.tu, data.tu);
  if(root == NULL){
    root = GetNewNode(data);
    return;
  }
  if(index == 0){
    printf("Try again\n");
    return;
  }
  else if(index > 0)
    Insert(root->left, data);
  else
    Insert(root->right, data);
  
}

void Search(Node *root, char *tucantim){
  int index;
  index = strcmp(root->data.tu, tucantim );
  if(root == NULL) return;
  if(index == 0) printf("%s : %s\n", root->data.tu, root->data.nghia);
  else if(index < 0)  Search(root->left, tucantim);
  else
    Search(root->right, tucantim);
}



/*void preorder(Node *root){
  if(root == NULL) return;
  else{
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right); 
  }
}

void inorder(Node *root){
  if(root == NULL) return;
  else{
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);    
  }
}

void postorder(Node *root){
  if(root == NULL) return;
  else{
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data); 
  }
}


*/
void reverseTree(Node *root){
  if(root != NULL){
    SWAP(root->left, root->right);
  if(root->left != NULL) return reverseTree(root->left);
  if(root->right != NULL) return reverseTree(root->right);
  }
}
