// Problem: Sort array of non-negative integers using counting sort.
// Find max, build freq array, compute prefix sums, build output.
#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n)
{
    int max = arr[0];

    // Find maximum element
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];

    // Initialize count array
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Store frequencies
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Compute prefix sums
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int output[n];

    // Build output array (stable)
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}