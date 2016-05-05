#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DNode {
	void *element;
	struct DNode *prev;
	struct DNode *next;
} DNode;

typedef struct dlist$ {
	DNode *root;
	DNode *last;
} dlist;

DNode *makeDDNode(void *val) {
	DNode *p;
	p = (DNode *)malloc(sizeof(DNode));
	p->next = NULL;
	p->prev = NULL;
	p->element = val;
	return p;
}

dlist *iniList(dlist *list) {
	list = (dlist *)malloc(sizeof(dlist));
	if (list == NULL) {
		fprintf(stderr, "ERROR : Allocated memory failed !!\n");
		exit(1);
	}
	list->root = NULL;
	list->last = NULL;
	return list;
}

//find the length of a list
int listLength(dlist *list) {
	DNode *p;
	int i = 0;
	p = list->root;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

void insertEnd(void *val, dlist *list) {
	DNode *p;
	p = makeDDNode(val);
	if (list->root == NULL) {
		list->root = p;
		list->last = p;
	}
	else
	{
		(list->last)->next = p;
		p->prev = list->last;
		list->last = p;
	}
}



void delDNode(DNode *p, dlist *list) {
	if (list->root == NULL)
		return;
	if (p == NULL)
		return;
	if (p == list->root) {
		list->root = list->root->next;

		free(p);
	}
	else if (p == list->last) {
		list->last = p->prev;
		p->prev->next = NULL;
		free(p);
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}

// insert DNode before DNode p
void insertBefore(DNode *p, void *val, dlist *list) {
	DNode *q = makeDDNode(val);
	if (list->root == NULL) {
		printf("DNode haven't create !!");
		return;
	} else if (list->root == p) {
		q->next = p;
	} else {
		q->next = p;
		q->prev = p->prev;
		p->prev->next = q;
	}
}

// insert DNode after DNode p
void insertAfter(DNode *p, void *val, dlist *list) {
	DNode *q = makeDDNode(val);
	if (list->root == NULL) {
		printf("DNode haven't create !!");
		return;
	} else {
		if (list->last == p) {
			insertEnd(val, list);
			free(q);
		}  else  {
			q->next = p->next;
			q->prev = p;
			p->next = q;	
		}
	}
}

void freeList(dlist * list) {
	if (list->root == NULL)
		return;
	DNode *to_free = list->root;
	while (to_free != NULL) {
		list->root = (list->root)->next;
		free(to_free); // free DNode
		to_free = list->root;
	}
}

