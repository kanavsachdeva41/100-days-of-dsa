/* Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10  */
#include <stdio.h>
#define max 100

int stack[max];
int top = -1;

void push(int value)
{
  if (top == max - 1)
  {
    printf("Stack overflow");
  }
  else
  {
    top++;
    stack[top] = value;
  }
}

void pop()
{
  if (top == -1)
  {
    printf("Stack underflow");
  }
  else
  {
    printf("%d", stack[top]);
    top--;
  }
}

void display()
{
  for (int i = top; i >= 0; i--)
  {
    printf("%d ", stack[i]);
  }
}

int main()
{
  int num;

  printf("Enter number of operations:");
  scanf("%d", &num);

  while (num--)
  {
    printf("\n---Stack menu---\n");
    printf("1.Push\n2.Pop\n3.Display\n");

    int choice, value;

    printf("Enter choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      scanf("%d", &value);
      push(value);
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    default:
      break;
    }
  }
}
