#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
  int data;
  Node *left;
  Node *right;
};

Node* GetNewNode(int data){
  Node *NewNode = (Node *)malloc(sizeof(Node));
  NewNode->data = data;
  NewNode->left = NULL;
  NewNode->right = NULL;
  return NewNode;
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

int countrightchild(Node *root){
  int count = 0;
  if(root == NULL)
    return 0;
   else{
    if(root->right != NULL) count = 1;
    return count + countrightchild(root->right) + countrightchild(root->left);
  }
}

int isleaf(Node *root){
if(root != NULL) return((leftchild(root) == NULL) && (rightchild(root) == NULL));
  return -1;
}



Node* Insert(Node *root, int data){
  if(root == NULL){
    root = GetNewNode(data);
    
  }
  else if(data <= root->data)
    root->left = Insert(root->left, data);
  else
    root->right = Insert(root->right, data);
  return root;

}

int Search(Node *root, int data){
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

int findHeight(Node *root){
  if(root == NULL)
    return -1;
  return max(findHeight(root->left), findHeight(root->right)) + 1;
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

int countNode(Node *root){
  int l, r;
  if(root == NULL) return 0;
  else{
    l = countNode(root->left);
    r = countNode(root->right);
    return l + r + 1;
  }
}

int FindMin(Node *root){
  if(root == NULL){
    printf("ERROR\n");
    return -1;
  }
  else if(root->left == NULL){
    return root->data;
  }
  return FindMin(root->left);
}

int FindMax(Node *root){
  if(root == NULL){
    printf("ERROR\n");
    return -1;
  }
  else if(root->right == NULL){
    return root->data;
  }
  return FindMax(root->right);
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

int IsSubtreeLesser(Node *root, int value){
  if(root == NULL) return 1;
  if(root->data <= value && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value))
    return 1;
  else
    return 0;
}

int IsSubtreeGreater(Node *root, int value){
 if(root == NULL) return 1;
  if(root->data <= value && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value))
    return 1;
  else
    return 0;
}

int IsBinarySearchTree(Node *root){
  if(root == NULL) return 0;
  if(IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right))
    return 0;
  else
    return 1;
    
}
