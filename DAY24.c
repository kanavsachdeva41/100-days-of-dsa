/* Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer. */
#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} n;

void main()
{
    n *p, *head, *temp;

    int num,found=0;

    printf("Enter number of nodes: ");
    scanf("%d", &num);

    head = (n*)malloc(sizeof(n));
    temp = (n*)malloc(sizeof(n));

    printf("Enter data for first node:");
    scanf("%d", &head->data);
    head->next = NULL;

    p = head;

    for(int i=2;i<=num;i++)
    {
        p->next=(n*)malloc(sizeof(n));
        p=p->next;
        printf("Enter data for node %d:", i);
        scanf("%d",&p->data);
        p->next = NULL;
    }

    int ele;

    printf("Enter element to be deleted from linked list:");
    scanf("%d", &ele);
 
    p = head; 
    
    while(p->next->data!=ele)
    {
        p=p->next;
    }

    if(p->next->data == ele)
    {
        found = 1;
        temp = p->next;
        p->next=temp->next;
        free(temp);
    }

    if(found == 0)
    {
        printf("Element not found");
    }

    p=head;

    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL");
}