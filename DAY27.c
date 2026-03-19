/* Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection. */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} n;

void main()
{
    n *p1,*head1,*p2,*head2;

    int num1;

    printf("Enter number of nodes: ");
    scanf("%d", &num1);

    head1=(n*)malloc(sizeof(n));

    printf("Enter data of node 1:");
    scanf("%d", &head1->data);
    head1->next = NULL;

    p1=head1;

    for(int i=2;i<=num1;i++)
    {
        p1->next=(n*)malloc(sizeof(n));
        p1=p1->next;
        printf("Enter data of node %d:", i);
        scanf("%d", &p1->data);
        p1->next=NULL;
    }

    int num2;

    printf("Enter number of nodes: ");
    scanf("%d", &num2);

    head2=(n*)malloc(sizeof(n));

    printf("Enter data of node 1:");
    scanf("%d", &head2->data);
    head2->next = NULL;

    p2=head2;

    for(int i=2;i<=num2;i++)
    {
        p2->next=(n*)malloc(sizeof(n));
        p2=p2->next;
        printf("Enter data of node %d:", i);
        scanf("%d", &p2->data);
        p2->next=NULL;
    }

    p1=head1,p2=head2;

    while(p1->data!=p2->data)
    {
        p1=p1->next;
        p2=p2->next;
    }

    printf("Value of intersection of two nodes: %d", p1->data);
}