#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef struct{
  char tu[max];
  char nghia[max];
} element_type;

typedef struct TNode {
	element_type info;
	struct TNode *left;
	struct TNode *right;
} TNode;

typedef TNode *tree_type;

void makeNullTree(tree_type *tree) {
	(*tree) = NULL;
}

TNode *makeTNode(element_type val) {
	TNode *p;
	p = (TNode *)malloc(sizeof(TNode));
	p->left = NULL;
	p->right = NULL;
	p->info = val;
	return p;
}

int emptyTree(tree_type tree) {
	return tree == NULL;
}

void freeTree(tree_type tree) {
	if (emptyTree(tree))
		return;
	freeTree(tree->left);
	freeTree(tree->right);
	free(tree);
	return;
}

void search(tree_type tree, char *tucantim) {
  int index = 0;
  //index = strcmp(tree->info.tu, tucantim);
  if (tree == NULL){
    printf("Not FOund\n");
    return;
  }
  index = strcmp(tree->info.tu, tucantim);
   if (index == 0)
    printf("%s : %s\n", tree->info.tu, tree->info.nghia);
  else if (index > 0)
     search(tree->left, tucantim);
  else if (index < 0)
     search(tree->right, tucantim);
}

void insert(tree_type *tree, element_type key) {
  int index = 0;
  
    if (*tree == NULL){
	  *tree = makeTNode(key);
	  return;
    }
    index = strcmp((*tree)->info.tu, key.tu);
  if(index == 0){
    printf("try again\n");
    return;
  }
  else if (index > 0)
    insert(&(*tree)->left, key);
  else if(index < 0)
    insert(&(*tree)->right, key);
}

element_type deleteMin (tree_type *tree ) {
	element_type key;
	if ((*tree)->left == NULL) {
		key = (*tree)->info;
		(*tree) = (*tree)->right;
		return key;
	}
	else return deleteMin(&(*tree)->left);
}

void delete(tree_type *tree, char *key)
{
  int index = 0;
  index = strcmp((*tree)->info.tu, key);
	if (*tree != NULL)
	{
		if (index < 0)
			delete(&(*tree)->left, key);
		else if (index > 0)
			delete(&(*tree)->right, key);
		else if ((*tree)->left == NULL && (*tree)->right == NULL)
			*tree = NULL;
		else if ((*tree)->left == NULL)
			*tree = (*tree)->right;
		else if ((*tree)->right == NULL)
			*tree = (*tree)->left;
		else
			(*tree)->info = deleteMin(&(*tree)->right);
	}
}

int height(tree_type tree) {
	int ld, rd;
	if (emptyTree(tree))
		return 0;
	ld = height(tree->left);
	rd = height(tree->right);
	return 1 + (ld > rd ? ld : rd);
}

/*void preOrder(tree_type tree, void (*order)(tree_type))
{
	if (tree != NULL)
	{
		order(tree);
		preOrder(tree->left, order);
		preOrder(tree->right, order);
	}
}

void inOrder(tree_type tree, void (*order)(tree_type))
{
	if (tree != NULL)
	{
		inOrder(tree->left, order);
		order(tree);
		inOrder(tree->right, order);
	}
}

void postOrder(tree_type tree, void (*order)(tree_type))
{
	if (tree != NULL)
	{
		postOrder(tree->left, order);
		postOrder(tree->right, order);
		order(tree);
	}
}

void reverseTree(tree_type *tree) {
	tree_type temp;

	if (*tree != NULL) {
		if ((*tree)->left != NULL)
			reverseTree(&(*tree)->left);
		if ((*tree)->right != NULL)
			reverseTree(&(*tree)->right);

		temp = (*tree)->left;
		(*tree)->left = (*tree)->right;
		(*tree)->right = temp;
	}
}

*/
/*void preorder(TNode *root){
  if(root == NULL) return;
  else{
    printf("%c ", root->info);
    preorder(root->left);
    preorder(root->right); 
  }
}
void inorder(TNode *root){
  if(root == NULL) return;
  else{
    inorder(root->left);
    printf("%c ", root->info);
    inorder(root->right);    
  }
}
void postorder(TNode *root){
  if(root == NULL) return;
  else{
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->info); 
  }
}
*/
