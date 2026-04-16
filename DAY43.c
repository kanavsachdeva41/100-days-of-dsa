/* Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6 */

#include <stdio.h>
#include <stdlib.h>

// node structure 
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} n;

//creation of new node
n* create(int data)
{
    n* new = (n*)malloc(sizeof(n));
    new->data=data;
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
    int front = 0, rear = 0;

    queue[rear++]=root;

    int i = 1;

    while(front<rear && i < size)
    {
        n* curr = queue[front++];

        if(i<size && arr[i]!=-1)
        {
            curr->left = create(arr[i]);
            queue[rear++] = curr->left;
        }

        i++;

        if(i<size && arr[i]!=-1)
        {
            curr->right = create(arr[i]);
            queue[rear++] = curr->right;
        }

        i++;
    }

    return root;
}

//transversal

void transversal(n* root)
{
    if(root == NULL)
      return;
    
    transversal(root->left);
    printf("%d ", root->data);
    transversal(root->right);
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

    transversal(root);

    return 0;
}
