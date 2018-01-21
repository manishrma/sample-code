#include <stdio.h>
#include "tBst.h"
/*
   struct node
   {
      int data;
      node* left;
      node* right;
   }*/
struct qlist *qfront = NULL;
struct qlist *qtail = NULL;

struct qlist *qalloc()
{
    struct qlist *q = (struct qlist *)malloc(sizeof(struct qlist));
    if (NULL == q)
    {
	return NULL;
    }
    q->data = 0;
    q->next = NULL;
    return q;
}
int qempty(void)
{
    if(qfront == NULL)
    {
	return 1;
    }
    return 0;
}
void qinsert(struct node *curr)
{
    if (NULL == curr)
    {
	return;
    }
    struct qlist *q = qalloc();
    if (NULL == q)
    {
	printf("unable to allocate mem \n");
	return;
    }
    q->data = curr;
    if (qtail == NULL)
    {
	qfront = q;
	qtail = q;
    }
    else
    {
	qtail->next = q;
	qtail = q;
    }

}
struct node *qpop(void)
{
    if (qfront == NULL)
    {
	return NULL;
    }
    struct qlist *curr = qfront;
    struct node *temp = curr->data;
    qfront = curr->next;
    free(curr);
    if (qfront == NULL)
	qtail = NULL;
    return temp;
}
void levelOrder(struct node * root)
{
    if (NULL == root)
    {
	return;
    }
    qinsert(root);
    while(!qempty())
    {
	struct node *curr = qpop();
	if (NULL == curr)
	{
	    printf("no curr found\n");
	    return;
	}
	printf("%d ", curr->data);
	qinsert(curr->left);
	qinsert(curr->right);
    }
}
#if 0
/************ traversal **************/
/* level order is by queue */
void qpush(struct node *root)
{
   struct list *list = rear;
   if (list == NULL)
   {
       list = malloc(sizeof(*list));
       list->data = root;
       list->next = NULL;
       front = queue = list;
       return;
   }
   rear->next = malloc(sizeof(*list));
   rear = rear->next;
   rear->data = root;
   rear->next = NULL;
}
struct node *qpop()
{
   struct list *list = front;
   struct list *next;
   struct node *data;

   if (list == NULL)
   {
       return NULL;
   }
   next = front->next;
   data = front->data;
   queue = next;
   
   free(front);
   front = queue;
}

int qempty()
{
    if(queue == NULL)
	return 1;
    return 0;
}
void level_order(struct node *root)
{
    struct node *q;
    if (root == NULL)
    {
	return;
    }

    qpush(root);
    while (!qempty())
    {
	q = qpop();
        printf("[%d] \n", q->data);
        qpush(q->left);
	qpush(q->right);
    }

}

#endif
