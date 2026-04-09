/* Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20 */
#include <stdio.h>
#include <stdlib.h>

# define size 5

int pq[size];
int front = -1, rear = -1;

void enqueue(int value)
{
    if(rear==size-1)
    {
        printf("Queue overflow");
        return;
    }

    if(front==-1)
    {
        front=rear=0;
        pq[rear]=value;
    }
    else
    {
        int i;

        for(i=rear;i>=front;i--)
        {
            if(value>pq[i])
            {
                pq[i+1]=pq[i];
            }
            else
            {
                break;
            }
        }

        pq[i+1]=value;
        rear++;
    }

    printf("%d inserted in priority queue", value);
}

void dequeue()
{
    if(front==-1)
    {
        printf("Queue Underflow");
        return;
    }

    printf("%d dequeued from priority queue", pq[front]);

    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if(front==-1)
    {
        printf("Queue is empty");
        return;
    }

    printf("Priority queue:");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ", pq[i]);
    }
}

int main()
{
    int choice,value;

    while (1)
    {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
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

            default:
                printf("Invalid choice\n");
        }
    }
}