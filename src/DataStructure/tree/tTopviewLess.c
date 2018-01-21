#include "tBst.h"
/*
 * struct node
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
struct vlist *vlhead = NULL;
struct vlist *vltail = NULL;

/*
 * struct qlist *qfront = NULL;
 * struct qlist *qtail = NULL;
 * */
#if 0
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
    if (vlhead == NULL)
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
    temp->next = vlhead;
    vlhead = temp;
    if (vltail == NULL)
	vltail = temp;
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
    if (NULL != vltail)
    {
	vltail->next  =  temp;
    }
    vltail = temp;
    if (NULL == vlhead)
    {
	vlhead = temp;
    }
}
int pop()
{
    struct vlist *temp = vlhead;
    int val;
    if (vlhead == NULL)
	return 0;
    val = vlhead->data;
    vlhead = vlhead->next;
    free(temp);
    return val;
}
#endif
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

