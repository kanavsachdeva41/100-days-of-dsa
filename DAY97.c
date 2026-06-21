// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Meeting;

int compareMeetings(const void *a, const void *b)
{
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heap operations
void heapifyUp(int heap[], int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index)
{
    while (1)
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

void push(int heap[], int *size, int value)
{
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

int popMin(int heap[], int *size)
{
    int minVal = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return minVal;
}

int main()
{
    int n;
    scanf("%d", &n);

    Meeting meetings[n];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &meetings[i].start, &meetings[i].end);

    qsort(meetings, n, sizeof(Meeting), compareMeetings);

    int heap[n];
    int heapSize = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++)
    {
        while (heapSize > 0 && heap[0] <= meetings[i].start)
            popMin(heap, &heapSize);

        push(heap, &heapSize, meetings[i].end);

        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }

    printf("%d\n", maxRooms);

    return 0;
}