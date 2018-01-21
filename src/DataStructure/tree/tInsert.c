#include "tBst.h"

/* create a new node with a value 
 */
struct node *new_node(int val)
{
    struct node *new;
    new = malloc(sizeof(*new));
    if (NULL == new)
    {
	printf("unable to allocate the memory");
	return NULL;
    }
    new->data = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}


struct node *insertNode(struct node *root, int val)
{
    if (root == NULL)
    {
        root = new_node(val);
        if (NULL == root)
        {
            printf("unable to allocate the memory");
            return NULL;
        }
    }
    else if (val < root->data)
    {
	root->left = insertNode(root->left, val);
    }
    else if (val > root->data)
    {
	root->right = insertNode(root->right, val);
    }
    return root;
}
