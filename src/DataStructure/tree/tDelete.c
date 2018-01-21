#include "tBst.h"

struct node *deleteNode(struct node *root, int val)
{
    if (root == NULL)
	return root;
    else if (val < root->data)
	root->left = deleteNode(root->left, val);
    else if (val > root->data)
	root->right = deleteNode(root->right, val);
    else
    {
	if (root->left == NULL && root->right ==NULL)
	{
	    free(root);
	    root = NULL;
	    return root;
	}
	else if (root->left == NULL)
	{
	    struct node *temp = root;
	    root = root->right;
	    free(temp);
            return root;
	}
	else if (root->right == NULL)
	{
	    struct node *temp = root;
	    root = root->left;
	    free(temp);
            return root;
	}
	else
	{
	    struct node *temp = findMin(root->right);
	    root->data = temp->data;
	    root->right = deleteNode(root->right, temp->data);
	}

    }
    return root;
}


