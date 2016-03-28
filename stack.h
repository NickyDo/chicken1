#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element_type;
typedef struct Node Node;
typedef struct Node{
	element_type info;
	Node *link;
} Node;

typedef struct stack_type${
	Node *top;
}stack_type;

int empty(stack_type *stack){
  return stack->top == NULL;
}

Node *makeNode()
{
	Node *t = (Node *)malloc(sizeof(Node));
	t->link = NULL;
	return t;		
}

void initialize(stack_type *stack)
{
	stack->top == NULL;
}

void push(element_type val, stack_type *stack){
Node *p;
p = makeNode();
p->info = val;
p->link = stack->top;
stack->top = p;
}

element_type pop(stack_type *stack)
{
	element_type val;
	Node *p = makeNode();
	if (empty(stack))
	  {
	    printf("\nStack overflow\n");
	    exit(0);
	  }
	val =  stack->top->info;
	p = stack->top;
	stack->top = stack->top->link;
	free(p);
	return val;
}
