/* Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} n;

n *create(int data){
    n *new = (n*)malloc(sizeof(n));
    new->data=data;
    new->right=NULL;
    new->left=NULL;

    return new;
}

n *insert(n* root, int data)
{
    if(root==NULL)
    {
        return create(data);
    }

    if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

int search(n *root,int key)
{
    if (root == NULL)
     return 0;

    if (root->data ==key)
     return 1;

    if ( key<root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right,key);
    }
}

int main()
{
    int size,x;

    printf("Enter numnber of nodes: ");
    scanf("%d", &size);

    n* root = NULL;

    for (int i = 0; i < size; i++) {
        printf("Enter data %d: ", i+1);
        scanf("%d", &x);
        root = insert(root, x);
    }

    int key;
    printf("Enter element to be searched: ");
    scanf("%d", &key);

    if(search(root,key))
    {
        printf("Element found!");
    }
    else
    {
        printf("Element not found");
    }

    return 0;

}