/*Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.

Sample Input
5 3
1 2 8 4 9

Sample Output
3
*/
#include <stdio.h>

// Helper function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sort array using simple bubble sort
void sort_array(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Check if we can place k cows with at least 'dist' distance apart
int can_place_cows(int stalls[], int n, int k, int dist) {
    int cows_placed = 1;           // Place first cow in first stall
    int last_position = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_position >= dist) {
            cows_placed++;
            last_position = stalls[i];
            if (cows_placed == k) {
                return 1;  // Successfully placed all k cows
            }
        }
    }

    return 0;  // Could not place all k cows
}

// Find maximum possible minimum distance using binary search
int maximized_min_distance(int stalls[], int n, int k) {
    // Sort the stall positions first
    sort_array(stalls, n);

    int low = 1;                    // Minimum possible distance
    int high = stalls[n - 1] - stalls[0];  // Maximum possible distance
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (can_place_cows(stalls, n, k, mid)) {
            result = mid;           // This distance is achievable
            low = mid + 1;          // Try for a larger distance
        } else {
            high = mid - 1;         // This distance is too large
        }
    }

    return result;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    printf("%d\n", maximized_min_distance(stalls, n, k));

    return 0;
}