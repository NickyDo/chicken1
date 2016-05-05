#include <stdio.h>
#include <stdlib.h>
#define SWAP(x , y) do { typeof(x) SWAP = (x); (x) = (y) ; (y) =SWAP;} while (0);

typedef struct TNode{
  int data;
  struct TNode *left;
  struct TNode *right;
} TNode;

typedef TNode *Tree_type;
TNode* GetNewNode(int data){
  TNode *NewNode = (TNode *)malloc(sizeof(TNode));
  NewNode->data = data;
  NewNode->left = NULL;
  NewNode->right = NULL;
  return NewNode;
}

int emptyTree(Tree_type tree) {
	return tree == NULL;
}

void freeTree(Tree_type tree) {
	if (emptyTree(tree))
		return;
	freeTree(tree->left);
	freeTree(tree->right);
	free(tree);
	return;
}

TNode* leftchild(TNode* root){
  if(root == NULL) return NULL;
  else
    return (root->left);
}

TNode* rightchild(TNode* root){
  if(root == NULL) return NULL;
  else
    return (root->right);
}

int countrightchild(TNode *root){
  int count = 0;
  if(root == NULL)
    return 0;
   else{
    if(root->right != NULL) count = 1;
    return count + countrightchild(root->right) + countrightchild(root->left);
  }
}

int isleaf(TNode *root){
if(root != NULL) return((leftchild(root) == NULL) && (rightchild(root) == NULL));
  return -1;
}



TNode* Insert(TNode *root, int data){
  if(root == NULL){
    root = GetNewNode(data);
    
  }
  else if(data <= root->data)
    root->left = Insert(root->left, data);
  else
    root->right = Insert(root->right, data);
  return root;

}

int Search(TNode *root, int data){
  if(root == NULL) return 0;
  if(root->data == data) return 1;
  else if(data <= root->data) return Search(root->left, data);
  else
    return Search(root->right, data);
}

int max(int x1, int x2){
  int maxi;
  if(x1 >= x2) maxi = x1;
  else maxi = x2;
  return maxi;
}

int findHeight(TNode *root){
  if(root == NULL)
    return -1;
  return max(findHeight(root->left), findHeight(root->right)) + 1;
}
int numberofleaf(TNode *root){
  int countl, countr, n = 0;
  if(root == NULL)
    return 0;
  else{
    countl = isleaf(root->left);
    countr = isleaf(root->right);
    if(countl != -1) n += countl;
    if(countr != -1) n += countr;
    return numberofleaf(root->left) + numberofleaf(root->right) + n; 
  }
 
}

int countNode(TNode *root){
  int l, r;
  if(root == NULL) return 0;
  else{
    l = countNode(root->left);
    r = countNode(root->right);
    return l + r + 1;
  }
}

int FindMin(TNode *root){
  if(root == NULL){
    printf("ERROR\n");
    return -1;
  }
  else if(root->left == NULL){
    return root->data;
  }
  return FindMin(root->left);
}

int FindMax(TNode *root){
  if(root == NULL){
    printf("ERROR\n");
    return -1;
  }
  else if(root->right == NULL){
    return root->data;
  }
  return FindMax(root->right);
}

void preorder(TNode *root){
  if(root == NULL) return;
  else{
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right); 
  }
}

void inorder(TNode *root){
  if(root == NULL) return;
  else{
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);    
  }
}

void postorder(TNode *root){
  if(root == NULL) return;
  else{
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data); 
  }
}

int IsSubtreeLesser(TNode *root, int value){
  if(root == NULL) return 1;
  if(root->data <= value && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value))
    return 1;
  else
    return 0;
}

int IsSubtreeGreater(TNode *root, int value){
 if(root == NULL) return 1;
  if(root->data <= value && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value))
    return 1;
  else
    return 0;
}

int IsBinarySearchTree(TNode *root){
  if(root == NULL) return 0;
  if(IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right))
    return 0;
  else
    return 1;
    
}

void reverseTree(TNode *root){
  if(root != NULL){
    SWAP(root->left, root->right);
  if(root->left != NULL) return reverseTree(root->left);
  if(root->right != NULL) return reverseTree(root->right);
  }
}


int DeleteMin(Tree_type *root){
  int k;
  if((*root)->left == NULL){
    k = (*root)->data;
    (*root) = (*root)->right;
    return k;
  }
  else return DeleteMin(&(*root)->left);
}


void DeleteNode(int x, Tree_type *root){
  if(*root == NULL) return;
  if(*root != NULL)
    if(x < (*root)->data)
      DeleteNode(x, &(*root)->left);
    else if(x > (*root)->data)
      DeleteNode(x, &(*root)->right);
    else if((*root)->left == NULL && (*root)->right == NULL)
      *root = NULL;
    else if((*root)->left == NULL)
      *root = (*root)->right;
    else if((*root)->right == NULL)
      *root = (*root)->left;
    else (*root)->data = DeleteMin(&(*root)->right);
}

TNode* findMin(TNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

TNode* Delete(TNode *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
		  free(root);
		  root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
		  TNode *temp = root;
		  root = root->right;
		  free(temp);
		}
		else if(root->right == NULL) {
			TNode *temp = root;
			root = root->left;
			free(temp);
		}
		// case 3: 2 children
		else { 
			TNode *temp = findMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
