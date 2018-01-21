#include "tBst.h"

void preOrder(struct node *root)
{
    if (root == NULL)
    {
	return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
