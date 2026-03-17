/* Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50 */

#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} n;

int main()
{ 
    n *p, *head;

    int num;

    printf("Enter number of nodes:");
    scanf("%d", &num);

    head = (n*)malloc(sizeof(n));

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

    //count

    int count = 0;
    p = head;

    while(p != NULL)
    {
        count++;
        p=p->next;
    }
    
    printf("Number of nodes = %d", count);

    return 0;
}