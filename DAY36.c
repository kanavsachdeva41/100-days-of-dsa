/* Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

// Enqueue
void enqueue(int value, int capacity)
{
    if(size == capacity)
        return;

    rear = (rear + 1) % capacity;
    queue[rear] = value;
    size++;
}

// Rotate (special dequeue for this problem)
void rotate(int capacity)
{
    if(size == 0)
        return;

    int temp = queue[front];           // take front element
    front = (front + 1) % capacity;   // move front

    rear = (rear + 1) % capacity;     // move rear
    queue[rear] = temp;               // put element at rear
}

// Display
void display(int capacity)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", queue[(front + i) % capacity]);
    }
}

int main()
{
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x, n);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        rotate(n);
    }

    display(n);

    return 0;
}