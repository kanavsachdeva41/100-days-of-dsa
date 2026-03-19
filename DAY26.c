/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer. */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} n;

void main()
{
    n *head, *p, *temp;

    head = (n*)malloc(sizeof(n));

    int num;

    printf("Enter number of nodes:");
    scanf("%d", &num);

    printf("Enter data for node 1:");
    scanf("%d", &head->data);

    head->next=NULL;
    head->prev=NULL;

    p=head;

    for(int i=2;i<=num;i++)
    {
        temp=(n*)malloc(sizeof(n));

        printf("Enter data for node %d:", i);
        scanf("%d", &temp->data);

        temp->next=NULL;
        temp->prev=p;

        p->next=temp;
        p=temp;
    }

    //Transveral

    p=head;

    printf("Linked list(forward transverse):");
    while(p!=NULL)
    {
        printf("%d->", p->data);
        p=p->next;
    }
    printf("NULL\n");
}