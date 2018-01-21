#include "tBst.h"

int heightOfTree(struct node* root)
{
    int hleft;
    int hright;
    // Write your code here.
    if (root == NULL)
    {
	return -1;
    }
    hleft = heightOfTree(root->left);
    hright = heightOfTree(root->right);

    return ((hleft > hright)? hleft: hright) + 1;
}

