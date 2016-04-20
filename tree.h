#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
typedef int element_type1;
typedef struct tNode tNode;
struct tNode{
  element_type data;
  tNode *left;
  tNode *right;
};

tNode* GetNewNode(element_type1 data){
  tNode *NewNode = (tNode *)malloc(sizeof(tNode));
  NewNode->data = data;
  NewNode->left = NULL;
  NewNode->right = NULL;
  return NewNode;
}

int emptytree(tNode *root){
  return root == NULL;
}

void freetree(tNode *root){
  if(emptytree(root)) return;
  freetree(root->left);
  freetree(root->right);
  free(root);
  return;
}

tNode* leftchild(tNode* root){
  if(root == NULL) return NULL;
  else
    return (root->left);
}

tNode* rightchild(tNode* root){
  if(root == NULL) return NULL;
  else
    return (root->right);
}

int isleaf(tNode *root){
if(root != NULL) return((leftchild(root) == NULL) && (rightchild(root) == NULL));
  return -1;
}

int countNode(tNode *root){
  int l, r;
  if(root == NULL) return 0;
  else{
    l = countNode(root->left);
    r = countNode(root->right);
    return l + r + 1;
  }
}

int numberofleaf(tNode *root){
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

int findHeight(tNode *root){
  if(root == NULL)
    return -1;
  return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void preorder(tNode *root){
  if(root == NULL) return;
  else{
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right); 
  }
}

void inorder(tNode *root){
  if(root == NULL) return;
  else{
   inorder(root->left);
   printf("%c ", root->data);
   inorder(root->right);
  }
}

void postorder(tNode *root){
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

// postfix expression
tNode *constructTree(char postfix[])
{
  int i;
  stack_type *p;
  p = (stack_type *)malloc(sizeof(stack_type));
  initialize(p);
  tNode *t, *t1, *t2;
  // Traverse through every character of
  // input expression
  for(i = 0; i<strlen(postfix); i++)
    {
      // If operand, simply push into stack
      if(isoperator(postfix[i]) == 1)
	{
	  t = GetNewNode(postfix[i]);
	  push(t, p);
	}
      else // operator
	{
	  t = GetNewNode(postfix[i]);
	  // Pop two top nodes
	  t1 = p->top;//store top
	  pop(p); //remove top
	  t2 = p->top;
	  pop(p);
	  //  make them children
	  t->right = t1;
	  t->left = t2;
	  // Add this subexpression to stack
	  push(t, p);
	}
    }

  //  only element will be root of expression
  // tree
  t = p->top;
  pop(p);
  
  return t;	  
}
