#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
typedef char element_type;
typedef struct Node Node;
struct Node{
  element_type data;
  Node *left;
  Node *right;
};

Node* GetNewNode(element_type data){
  Node *NewNode = (Node *)malloc(sizeof(Node));
  NewNode->data = data;
  NewNode->left = NULL;
  NewNode->right = NULL;
  return NewNode;
}

int emptytree(Node root){
  return root == NULL;
}

void freetree(Node root){
  if(emptytree(root)) return;
  freetree(root->left);
  freetree(root->right);
  free(root);
  return;
}

Node* leftchild(Node* root){
  if(root == NULL) return NULL;
  else
    return (root->left);
}

Node* rightchild(Node* root){
  if(root == NULL) return NULL;
  else
    return (root->right);
}

int isleaf(Node *root){
if(root != NULL) return((leftchild(root) == NULL) && (rightchild(root) == NULL));
  return -1;
}

int countNode(Node *root){
  int l, r;
  if(root == NULL) return 0;
  else{
    l = countNode(root->left);
    r = countNode(root->right);
    return l + r + 1;
  }
}

int numberofleaf(Node *root){
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

int max(int x1, int x2){
  int maxi;
  if(x1 >= x2) maxi = x1;
  else maxi = x2;
  return maxi;
}

int findHeight(Node *root){
  if(root == NULL)
    return -1;
  return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void preorder(Node *root){
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
   printf("%c ", root->data);
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

/*void calInorder(Node *tree) {
  if (emptytree(tree))
    return 0;
  else if (tree->info.val == 0)
    switch (tree->info.operator) {
		case '+': return calInorder(left) + calInorder(right);
    case '-': return calInorder(left) - calInorder(right);
    case '.': return calInorder(left) * calInorder(right);
    case '/': return calInorder(left) / calInorder(right);
    }
  return tree->info.val;
}
*/

int isoperator(char c){
  if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    return 1;
  return 0;
}

Node *constructTree(char postfix[])
{
  int i;
  stack_type *p;
  p = (stack_type *)malloc(sizeof(stack_type));
  initialize(p);
  Node *t, *t1, *t2;
  for(i = 0;  i<strlen(postfox); i++)
    {
      if(isoperator(postfix))
	{
	  t = GetNewNode(postfix[i]);
	  push(t, p);
	}
      else
	{
	  t = GetNewNode(postfix[i]);
	  t1 = p->top;
	  pop(p);
	  t2 = p->top;
	  pop(p);

	  t->right = t1;
	  t->left = t2;

	  push(t, p);
	}
    }
  t = p->top;
  pop(p);
  return t;
	  
}
