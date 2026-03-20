/* Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order. */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int coeff;
    int expo;
    struct node *next;
} n;

void main()
{
    n *head,*temp;

    int num;

    printf("Enter number of inputs:");
    scanf("%d", &num);

    head=(n*)malloc(sizeof(n));

    printf("Enter node 1 coeff:");
    scanf("%d", &head->coeff);
    printf("Enter node 2 expo:");
    scanf("%d", &head->expo);

    head->next=NULL;

    temp=head;

    for(int i=2;i<=num;i++)
    {
        temp->next=(n*)malloc(sizeof(n));
        temp=temp->next;
        printf("Enter coeff of node %d:", i);
        scanf("%d", &temp->coeff);
        printf("Enter expo of node %d:", i);
        scanf("%d", &temp->expo);
        temp->next=NULL;
    }

    temp=head;

    while(temp!=NULL)
    {
        printf("%dx^%d", temp->coeff,temp->expo);
        printf("+");
        temp=temp->next;
    }
    printf("0");
}