/* Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3
*/
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

int height(n *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
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

    printf("Height of binary tree: %d\n", height(root));

    return 0;
}


