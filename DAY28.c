/* Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop. */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} n;

void main()
{
    n *p,*head,*temp;

    head=(n*)malloc(sizeof(n));

    int num;

    printf("Enter number of nodes: ");
    scanf("%d", &num);

    printf("Enter data for node 1:");
    scanf("%d", &head->data);
    head->next=NULL;

    p=head;

    for(int i=2;i<=num;i++)
    {
        temp=(n*)malloc(sizeof(n));
        printf("Enter data for node %d:", i);
        scanf("%d", &temp->data);
        temp->next=NULL;

        p->next=temp;
        p=temp;
    }

    p->next=head;

    temp=head;

    printf("%d ",temp->data);
    temp=temp->next;

    while(temp!=head)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
}