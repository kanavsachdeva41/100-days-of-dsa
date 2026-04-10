/* Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operation */
#include <stdio.h>
#include <stdlib.h>

#define size 10

int deque[size];
int front=-1, rear=-1;

int isfull()
{
    return (front==0 &&  rear==size-1);
}

int isempty()
{
    return front==-1;
}

void push_front(int value)
{
    if(isfull())
    {
        printf("Deque overflow");
        return;
    }

    if(isempty())
    {
        front=rear=0;
    }
    else if(front==0)
    {
        front=size-1;
    }
    else
    {
        front--;
    }

    deque[front]=value;
}

void push_rear(int value)
{
    if(isfull())
    {
        printf("Deque overflow");
        return;
    }

    if(isempty())
    {
        front=rear=0;
    }
    else if(rear=size-1)
    {
        rear=0;
    }
    else
    {
        rear++;
    }

    deque[rear]=value;
}

void pop_front()
{
    if(isempty())
    {
        printf("Deque underflow");
        return;
    }

    if(front==rear)
    {
        front=rear=-1;
    }
    else if(front==size-1)
    {
        front=0;
    }
    else
    {
        front++;
    }
}

void pop_rear()
{
    if(isempty())
    {
        printf("Deque overflow");
        return;
    }
    
    if(front==rear)
    {
        front=rear=-1;
    }
    else if(rear==0)
    {
        rear=size-1;
    }
    else{
        rear--;
    }
}

void get_front()
{
    if(isempty())
    {
        printf("Deque is empty");
    }
    else
    {
        printf("Front element of deque: %d", deque[front]);
    }
}

void get_rear()
{
    if(isempty())
    {
        printf("Deque is empty");
    }
    else
    {
        printf("Rear element of deque: %d", deque[rear]);
    }
}

int get_size()
{
    if(isempty()) return 0;
    else
    {
        if(rear>=front)
        {
            return rear-front+1;
        }
        else
        {
            return size-rear+front+1;
        }
    }
}

void display()
{
    if(isempty())
    {
        printf("Deque is empty");
        return;
    }

    printf("Deque elements: ");
    int i = front;

    while(1)
    {
        printf("%d ", deque[i]);
        if(i==rear) break;
        i=(i+1)%size;
    }
}

void clear()
{
    front=rear=-1;
}

void reverse() {
    if (isempty()) return;

    int temp[size], i = front, j = 0;

    while (1) {
        temp[j++] = deque[i];
        if (i == rear) break;
        i = (i + 1) % size;
    }

    for (int k = 0; k < j / 2; k++) {
        int t = temp[k];
        temp[k] = temp[j - k - 1];
        temp[j - k - 1] = t;
    }

    front = 0;
    rear = j - 1;
    for (int k = 0; k < j; k++) {
        deque[k] = temp[k];
    }
}

int main()
{
    int choice,value;

    while (1)
    {
        printf("\n--- Deque Menu ---\n");
        printf("1. Push_front\n2. Push_back\n3. Pop_front\n4. pop_back\n5. Get_front\n6. Get_rear\n7. Get_size\n8. Display\n9. Clear\n10. Reverse\n11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push_rear(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_rear();
                break;
            
            case 5:
                get_front();
                break;
            
            case 6:
                get_rear();
                break;

            case 7:
                get_size();
                break;

            case 8:
                display();
                break;

            case 9:
                clear();
                break;
            
            case 10:
                reverse();
                break;

            case 11:
                return 0;
                break;

            default:
                printf("Invalid choice\n");
        }
    }
}