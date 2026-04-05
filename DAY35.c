/* Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear. */
#include <stdio.h>
#define max 10

int queue[max];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == max - 1)
    {
        printf("Queue Overflow");
    }
    else
    {
        if (front = -1)
        {
            front = 0;
        }
        queue[++rear] = value;
        printf("%d enqueued in queue", value);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue underflow");
    }
    else
    {
        printf("%d deleted from queue", queue[front++]);
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int value, choice;
    while (1)
    {
        printf("\n---Queue menu---\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value:");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Enter invalid choice");
            break;
        }
    }
}
