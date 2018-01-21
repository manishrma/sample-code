#include "tBst.h"

struct node *findMin(struct node *root)
{
    if (root == NULL)
    {
	return NULL;
    }
    else if(NULL == root->left)
    {
        return root;
    }
    else
    {
	return findMin(root->left);
    }

}


