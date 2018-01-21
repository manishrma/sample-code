#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "tBst.h"

struct node *head = NULL;
struct node *end = NULL;
struct list *queue, *front, *rear;

struct node _root;
struct node *root = &_root;

enum action {
    insert_node =0,
    delete_node,
    search_node,
    print_tree,
    height,
    find_min,
    inorder,
    preorder,
    postorder,
    level_traversal,
    check_bst,
    topview,
    exitfn,
};

int main ()
{
    int val;

choice:
    printf("Binary Search Tree \n");
    printf("Choose the selection:\n");
    printf("%d.Add a node\n", insert_node);
    printf("%d.Delete a node\n", delete_node);
    printf("%d.Search a node\n", search_node);
    printf("%d.Print the tree\n", print_tree);
    printf("%d.Print height of the tree\n", height);
    printf("%d.Find Min value in the tree\n", find_min);
    printf("%d.Print inorder traversal\n", inorder);
    printf("%d.Print preorder traversal\n", preorder);
    printf("%d.Print postorder traversal\n", postorder);
    printf("%d.Print level order traversal\n", postorder);
    printf("%d.Check the tree is binary search tree. \n", check_bst);
    printf("%d.Print Top View of binary search tree \n", check_bst);
    printf("%d.Exit\n", exitfn);
    printf(":");
getvalue:
    scanf("%d",&val);
    switch (val)
    {
	case insert_node:
	{
	    int data =0;
	    printf("Enter value to insert:");
	    scanf("%d", &data);
	    insertNode(root, data);
	    break;
	}
	case delete_node:
        {
	    int data =0;
	    printf("Enter value to delete:");
	    scanf("%d", &data);
	    root = deleteNode(root, data);
	    break;
	}

	case search_node:
        {
	    int data =0;
	    struct node *item = NULL;
	    printf("Enter value to search:");
	    scanf("%d", &data);
	    item = searchNode(root, data);
	    if (item)
	    {
		printf("Found item at node %p : %d \n", item, item->data);
	    }
	    else
	    {
		printf("No Data Found\n");
	    }
	    break;
	}
	case height:
        {
	    int val = -1;
	    val = heightOfTree(root);
	    printf("Height of the tree is %d \n:", val);
	    break;
	}
	case find_min:
        {
	    printf("Minimum in the tree is %d \n:", ((struct node *)findMin(root))->data);
	    break;
	}
	case inorder:
        {
	    printf("Printing inorder tree :-\n");
	    inOrder(root);
	    break;
	}
	case preorder:
        {
	    printf("Printing preorder tree :-\n");
	    preOrder(root);
	    break;
	}
	case postorder:
        {
	    printf("Printing postorder tree :-\n");
	    postOrder(root);
	    break;
	}
	case level_traversal:
        {
	    printf("Printing level order tree :-\n");
	    postOrder(root);
	    break;
	}
	case check_bst:
        {
	    printf("The tree is %s BST tree \n", checkBST(root)?"":"not");
	    break;
	}
	case topview:
	{
	    printf("Printing Top view of the tree :-\n");
	    topView(root);
	    break;
	}
	case exitfn:
	{
	    //free the mem and exitfn
	    printf("Bye");
	    return 0;
	}
	default:
	{
            printf("Wrong Selection \b");
	    goto getvalue;
	}
    }
    goto choice;
}
