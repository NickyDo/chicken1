#include "dlink.h"

typedef struct {
	dlist *list;
	void *position;
} queue_type;

int Qempty(queue_type *q) {
	return q->position == NULL;
}

queue_type *iniQueue(queue_type *q) {
	q = (queue_type *)malloc(sizeof(queue_type));
	q->list = iniList(q->list);
	q->position = 0;
	return q;
}

void enQueue(void *val, queue_type *q) {
	insertEnd(val, q->list);
	q->position++;
}

void *deQueue(queue_type *q) {
	void *val;
	Node *p;
	if (!Qempty(q))
	{
		val = q->list->root->element;
		delDNode(q->list->root, q->list);
		q->position--;	
		return val;
	}
	else
		printf("Empty queue!\n");
}

void removeQueue(queue_type *q)
{
	if(q == NULL)
		return;
	if(q->list == NULL)
		return;
	if (q != NULL)
		freeList(q->list);
	free(q);
}