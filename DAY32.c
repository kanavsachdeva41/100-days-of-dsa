/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10 */
#include <stdio.h>
#define max 100
int n;
int stack[max];
int top=-1;

void push(int value,int n)
{
    if(top==n-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top]=value;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
    }
    else
    {
        top--;
    }
}

int main()
{
    printf("Enter number of integers to be push into stack:");
    scanf("%d", &n);

    int value;

    for(int i=0;i<n;i++)
    {
       printf("Enter value %d:", i+1);
       scanf("%d", &value);
       push(value,n);
    }

    int m;

    printf("Enter number of pop operations:");
    scanf("%d", &m);

    for(int i=0;i<m;i++)
    {
        pop();
    }

    printf("Resultant stack:");

    for(int i=n-m-1;i>=0;i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}