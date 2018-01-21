#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Need a queue for the level traversal
struct queue{
    struct node *n;
    struct queue *next;
};
struct queue *qfront, *qtail;

struct queue *create_qnode(struct node *n)
{
    struct queue *curr = (struct queue *)malloc(sizeof(struct queue));
    if (curr == NULL)
    {
	printf("unable to allocate queue \n");
	return NULL;
    }
    curr->n = n;
    curr->next = NULL;
    return curr;
}
void qinsert(struct node *n)
{
    struct queue *curr = create_qnode(n);
    if (curr == NULL)
    {
	return;
    }
    if (qfront == NULL)
    {
	qfront = curr;
	qtail = curr;
    }
    else
    {
        qtail->next = curr;
        qtail = curr;
    }
    //printf("qinsert %d \n", n->data);
}
struct node *dequeue()
{
    struct node *n;
    struct queue *temp;

    if (qfront == NULL)
    {
	printf("queue empty \n");
	return NULL;
    }
    temp = qfront;
    n = qfront->n;
    qfront = temp->next;
    
    free(temp);
    //printf("dequeue %d\n ", n->data);
    return n;
}

struct node *create_node(int data)
{
    struct node *curr = NULL;
    curr = (struct node *)malloc(sizeof(struct node));
    if (curr == NULL)
    {
	printf("unable to allocate mem \n");
	return NULL;
    }
    curr->data = data;
    curr->left = NULL;
    curr->right = NULL;
    return curr;
}

// inorder traversal
void inorder(struct node *root)
{
    if (root == NULL)
	return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


// Swapping every kth node of the tree 
void swap_nodes(struct node **left, struct node **right)
{
    struct node *temp = *left;
    *left  = *right;
    *right = temp;
}
void swap_kth_node(struct node *root, int level, int kth)
{
    if (root == NULL)
	return;
    if (root->left == NULL &&
	    root->right == NULL)
	return;
    if ((level >=  kth) && ((level % kth) == 0))
    {
	//printf("swapping level %d : %d \n", level , kth);
        swap_nodes(&root->left, &root->right);
    }

    swap_kth_node(root->left, level+1, kth);
    swap_kth_node(root->right, level+1, kth);
}
/*
 Input Format
 First line of input contains N, number of nodes in tree.
 Then N lines follow. Here each of ith line (1 <= i <= N) contains two integers, a b,
 where a is the index of left child, and b is the index of right child of ith node. -1 is used to represent null node.
 Next line contain an integer, T. Then again T lines follows. Each of these line contains an integer K.
 */
struct node *parse_tree()
{
    int node_pairs, val;
    struct node *root;
    struct node *curr;
    /* root is always 1*/
 
    root = create_node(1);
    if (root == NULL)
    {
	printf("Unable to allocate the node \n");
	return NULL;
    }
    curr = root;
    // Add root to stack;
    qinsert(root);
    //printf("Enter the values: \n");
    scanf("%d", &node_pairs);
    for(int i=0; i< node_pairs; i++)
    {
	// Take the first element out
	curr = dequeue();
	// creating left node
        scanf("%d", &val);
	if (val != -1)
	{
	     //printf(" adding val to left %d \n", val);
             curr->left = create_node(val);
	     // push left node
	     qinsert(curr->left);
	}
	// creating right node
        scanf("%d", &val);
	if (val != -1)
	{
	     //printf(" adding val to right %d \n", val);
             curr->right = create_node(val);
	     // push the right node
	     qinsert(curr->right);
	}
    }
    return root;
}
int main()
{
    struct node *root;
    int count;
    int level, kth;
    root = parse_tree();

    //printf("Current tree :- \n");
    //inorder(root);
    //printf("\n");

    // Get the values to be swapped.
    scanf("%d", &count);
    //printf(" swapping %d times \n", count);
    for(int i =0; i< count; i++)
    {
        scanf("%d", &kth);
        swap_kth_node(root, 1, kth);
        inorder(root);
        printf("\n");
    }

    //printf("Updated tree :- \n");
    return 0;
}
