#include "tree.h"

int main(){
  char postfix[] = "ab+ef*g*-";
  tNode *r = constructTree(postfix);
  printf("infix expression is\n");
  inorder(r);
  printf("\n");
  return 0;
}
