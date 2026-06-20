/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/
#include <stdio.h>

// Find maximum element in array
int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Calculate sum of all elements
int find_sum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Check if we can paint all boards within 'time' with at most k painters
int can_paint_within_time(int arr[], int n, int k, int time) {
    int painters_used = 1;   // Start with first painter
    int current_sum = 0;

    for (int i = 0; i < n; i++) {
        // If a single board takes more time than 'time', impossible
        if (arr[i] > time) {
            return 0;
        }

        // If adding this board exceeds 'time', assign to next painter
        if (current_sum + arr[i] > time) {
            painters_used++;
            current_sum = arr[i];
            
            // If we need more than k painters, not feasible
            if (painters_used > k) {
                return 0;
            }
        } else {
            current_sum += arr[i];
        }
    }

    return 1;  // Successfully painted with k or fewer painters
}

// Find minimum time required using binary search
int minimize_painting_time(int arr[], int n, int k) {
    // If more painters than boards, we can use only n painters effectively
    if (k > n) {
        k = n;
    }

    int low = find_max(arr, n);     // At least the largest board
    int high = find_sum(arr, n);    // At most all boards to one painter
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (can_paint_within_time(arr, n, k, mid)) {
            result = mid;            // This time is feasible
            high = mid - 1;          // Try to minimize further
        } else {
            low = mid + 1;           // Need more time per painter
        }
    }

    return result;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minimize_painting_time(arr, n, k));

    return 0;
}