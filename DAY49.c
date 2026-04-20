/* Problem: BST Insert

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

void inorder(n *root)
{
    if(root == NULL)
      return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    inorder(root);
    return 0;

}