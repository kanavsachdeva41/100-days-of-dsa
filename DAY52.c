/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} n;

n *create(int data)
{
    n *new =(n*)malloc(sizeof(n));
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    return new;
}

n* tree(int arr[], int size)
{
    if(size == 0 || arr[0] == -1)
    {
        return NULL;
    }

    n* root = create(arr[0]);

    n* queue[size];
    int front= 0, rear = 0;

    queue[rear++]=root;

    int i=1;

    while(front<rear && i<size)
    {
        n* curr = queue[front++];

        if(i<size && arr[i]!=-1)
        {
            curr->left = create(arr[i]);
            queue[rear++]=curr->left;
        }

        i++;

        if(i<size && arr[i]!=-1)
        {
            curr->right = create(arr[i]);
            queue[rear++]=curr->right;
        }

        i++;
    }
    return root;
}

void inorder(n* root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

n *LCA(n *root, int a , int b)
{
    if (root == NULL)
      return NULL;
    
    if(root->data == a || root->data == b)
      return root;
    
    n* left = LCA(root->left, a, b);
    n* right = LCA(root->right, a, b);

    if(left && right)
        return root;

    return (left != NULL) ? left : right;
}


int main()
{
    int size;

    printf("Enter number of elements of tree:");
    scanf("%d", &size);

    printf("Enter elements:");
    int arr[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);
    }

    n* root=tree(arr,size);

    int a,b;

    printf("Enter two nodes: ");
    scanf("%d %d", &a, &b);

    n* lca = LCA(root, a, b);

    if(lca != NULL)
        printf("LCA of %d and %d is: %d", a, b, lca->data);
    else
        printf("LCA not found");

    return 0;
}