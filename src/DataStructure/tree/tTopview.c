#include "tBst.h"
/*
   struct node
   {
       int data;
       node* left;
       node* right;
   };

*/
struct vlist{
    int data;
    struct vlist *next;
};
struct vlist *vhead = NULL;
struct vlist *vtail = NULL;

struct qvlist *qvfront = NULL;
struct qvlist *qvtail = NULL;

struct vlist *alloc_vlist()
{
    struct vlist *list = (struct vlist *)malloc(sizeof(struct vlist));
    if (NULL == list)
    {
	printf("unable to allocate vlist \n");
	return NULL;
    }
    list->data = 0;
    list->next = NULL;
    return list;
}
int vlist_empty()
{
    if (vhead == NULL)
    {
	return 1;
    }
    return 0;
}
void put_front(int val)
{
    struct vlist *temp = alloc_vlist();
    if (NULL == temp)
    {
	printf("unable to alocate \n");
	return;
    }
    temp->data = val;
    temp->next = vhead;
    vhead = temp;
    if (vtail == NULL)
	vtail = temp;
}
void put_back(int val)
{
    struct vlist *temp = alloc_vlist();
    if (NULL == temp)
    {
	printf("unable to alocate \n");
	return;
    }
    temp->data = val;
    if (NULL != vtail)
    {
	vtail->next  =  temp;
    }
    vtail = temp;
    if (NULL == vhead)
    {
	vhead = temp;
    }
}
int pop()
{
    struct vlist *temp = vhead;
    int val;
    if (vhead == NULL)
	return 0;
    val = vhead->data;
    vhead = vhead->next;
    free(temp);
    return val;
}
/**********************************/
struct qvlist *alloc_qnode()
{
    struct qvlist *q = (struct qvlist *)malloc(sizeof(struct qvlist));
    if (NULL == q)
    {
	printf("unable to allocate vlist \n");
	return NULL;
    }
    q->data = NULL;
    q->next = NULL;
    q->vlevel = 0;
    return q;
}
int qvempty()
{
    if(NULL == qvfront)
	return 1;
    return 0;
}
void qvinsert(struct node *node, int vlevel)
{
    struct qvlist *temp = NULL;
    if (node == NULL)
    {
	return;
    }
    temp = alloc_qnode();
    if (NULL == temp)
    {
	printf("unable to alocate \n");
	return;
    }
    printf("data %d: level %d \n",node->data, vlevel);
    temp->data = node;
    temp->vlevel = vlevel;
    temp->next = NULL;
    if (qvtail != NULL)
    {
	qvtail->next = temp;
    }
    qvtail = temp;
    if (qvfront == NULL)
    {
	qvfront = temp;
    }
}
struct node *qvpop(int *level)
{
    struct qvlist *temp = qvfront;
    struct node *data;
    if (NULL == temp)
    {
	printf("q empty\n");
	return NULL;
    }
    qvfront = qvfront->next;
    data = temp->data;
    *level = temp->vlevel;
    free(temp);
    return data;
}

#ifdef TOPVIEW_LESS
void leftView(struct node *root)
{
    if (root == NULL)
    {
	return;
    }
    put_front(root->data);
    leftView(root->left);
}
void rightView(struct node *root)
{
    if (root == NULL)
    {
	return;
    }
    put_back(root->data);
    rightView(root->right);
}

void topView_less(struct node * root)
{
    if (root == NULL)
    {
	return;
    }
    put_front(root->data);
    leftView(root->left);
    rightView(root->right);
    while(!vlist_empty())
    {
	printf("%d ", pop());
    }
}

#else
void topView(struct node * root)
{
    int llevel = -1;
    int rlevel = 1;
    if (root == NULL)
    {
	return;
    }
    put_front(root->data);
    qvinsert(root->left, -1);
    qvinsert(root->right, 1);
    while(!qvempty())
    {
	int vlevel;
	struct node *curr = qvpop(&vlevel);
	if (curr != NULL)
	{
	    if (vlevel == llevel)
	    {
		put_front(curr->data);
		llevel--;
	    }
	    else if (vlevel == rlevel)
	    {
		put_back(curr->data);
		rlevel++;
	    }
	    qvinsert(curr->left, vlevel-1);
	    qvinsert(curr->right, vlevel+1);
	}
    }
    while(!vlist_empty())
    {
	printf("%d ", pop());
    }
}
#endif
