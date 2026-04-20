/* Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6 */
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

n *LCA(n *root,int a, int b)
{
    if (root == NULL)
     return NULL;

    if (root->data > a && root->data > b)
        return LCA(root->left, a, b);

    if (root->data < a && root->data < b)
        return LCA(root->right, a, b);

    return root;
}

int main()
{
    int size,x,a,b;

    printf("Enter numnber of nodes: ");
    scanf("%d", &size);

    n* root = NULL;

    for (int i = 0; i < size; i++) {
        printf("Enter data %d: ", i+1);
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("give two nodes:");
    scanf("%d %d", &a, &b);

    n* lca = LCA(root,a ,b);

    if(lca != NULL)
    {
        printf("%d", lca->data);
    }

    return 0;

}