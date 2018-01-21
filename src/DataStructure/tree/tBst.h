#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct qlist{
    struct node *data;
    struct qlist *next;
};

struct qvlist{
    struct node *data;
    int vlevel;
    struct qvlist *next;
};

struct list {
   struct node *data;
   struct list *next;
};

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void postOrder(struct node *root);
void preOrder(struct node *root);
void inOrder(struct node *root);
int heightOfTree(struct node* root);
bool checkBST(struct node* root);
void levelOrder(struct node * root);
void topView(struct node * root);
void topView_less(struct node * root);
struct node *deleteNode(struct node *root, int val);
struct node *insertNode(struct node *root, int val);
struct node *searchNode(struct node *root, int val);
struct node *findMin(struct node *root);
