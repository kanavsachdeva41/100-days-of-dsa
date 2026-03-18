/* Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count. */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} n;

void main()
{
    n *p,*head;

    int num;

    printf("Enter number of nodes: ");
    scanf("%d", &num);

    head=(n*)malloc(sizeof(n));

    printf("Enter data of node 1:");
    scanf("%d", &head->data);
    head->next = NULL;

    p=head;

    for(int i=2;i<=num;i++)
    {
        p->next=(n*)malloc(sizeof(n));
        p=p->next;
        printf("Enter data of node %d:", i);
        scanf("%d", &p->data);
        p->next=NULL;
    }

    int ele;

    printf("Enter element to be searched:");
    scanf("%d", &ele);

    int count=0;

    p=head;

    while(p!=NULL)
    {
        if(p->data==ele)
        {
            count++;
            p=p->next;
        }
        else
        {
            p=p->next;
        }
    }

    printf("Count: %d", count);
}