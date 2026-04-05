/* Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}n;

n *front=NULL, *rear=NULL;

void enqueue(int value)
{
    n *temp= (n*)malloc(sizeof(n));
    temp->data=value;
    temp->next=NULL;

    if(rear==NULL)
    {
       rear=front=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
    printf("%d inserted in Queue", value);
}

void dequeue()
{
    if(front==NULL)
    {
        printf("Queue underflow");
    }
    else
    {
        n *temp=front;
        printf("%d deletef from queue", front->data);
        front=front->next;
        free(temp);
    }
}

void display()
{
    n *p=front;
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
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
