/*Problem: Height of Binary Tree (bfs)

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
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

int level(n *root)
{
    if(root == NULL)
     return 0;

    n* queue[100];
    int front = 0, rear = 0;

    queue[rear++]=root;

    int height = 0;
    while(front<rear)
    {
        int size = rear - front;

        for(int i=0;i<size;i++)
        {
            n* curr =  queue[front++];

            if(curr->left)
            {
                queue[rear++]=curr->left;
            }

            if(curr->right)
            {
                queue[rear++]=curr->right;
            }
        }
        height++;
    }
    return height;
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

    printf("Height of binry tree(bfs): %d", level(root));

    return 0;
}


