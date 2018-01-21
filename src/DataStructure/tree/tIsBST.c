#include "tBst.h"
/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  
 *
 * The Node struct is defined as follows:
 *    struct node {
 *         int data;
 *         struct node* left;
 *         struct node* right;
 *    }
 */
bool IsTreeLesser(struct node* root, int data)
{
    if (root == NULL)
	return true;
    if (root->data < data && \
	    IsTreeLesser(root->left, data) &&
	    IsTreeLesser(root->right, data))
    {
	return true;
    }
    return false;

}
bool IsTreeGreater(struct node* root, int data)
{
    if (root == NULL)
	return true;
    if (root->data > data && \
	    IsTreeGreater(root->left, data) &&
	    IsTreeGreater(root->right, data))
    {
	return true;
    }
    return false;
}
bool checkBST(struct node* root)
{
    if (NULL == root)
    {
	return true;
    }
    if (IsTreeLesser(root->left, root->data) && \
	    IsTreeGreater(root->right, root->data) && \
	    checkBST(root->left) && \
	    checkBST(root->right))
    {
	return true;
    }
    return false;
}

