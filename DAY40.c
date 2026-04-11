./* Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.

Here’s a clean implementation of Heap Sort using a Max Heap (ascending order) in */
#include <stdio.h>

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function (Max Heap)
void heapify(int arr[], int n, int i)
{
    int largest = i;        // root
    int left = 2*i + 1;     // left child
    int right = 2*i + 2;    // right child

    // Check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If root is not largest
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest); // recursively heapify
    }
}

// Heap Sort function
void heapSort(int arr[], int n)
{
    // Step 1: Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one
    for (int i = n-1; i > 0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // call heapify on reduced heap
        heapify(arr, i, 0);
    }
}

// Print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main
int main()
{
    int arr[] = {40, 10, 30, 50, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}