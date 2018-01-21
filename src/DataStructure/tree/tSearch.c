#include "tBst.h"

struct node *searchNode(struct node *root, int val)
{
    if (root == NULL)
    {
	return NULL;
    }
    else if (root->data == val)
    {
	return root;
    }
    else if (val < root->data)
    {
	return searchNode(root->left, val);
    }
    else if (val > root->data)
    {
        return searchNode(root->right, val);
    }
}


