/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113*/
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

// Check if we can allocate books with max 'pages' per student
int can_allocate(int arr[], int n, int m, int pages) {
    int students_used = 1;   // Start with first student
    int current_sum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than 'pages', impossible
        if (arr[i] > pages) {
            return 0;
        }

        // If adding this book exceeds 'pages', assign to next student
        if (current_sum + arr[i] > pages) {
            students_used++;
            current_sum = arr[i];
            
            // If we need more than m students, not feasible
            if (students_used > m) {
                return 0;
            }
        } else {
            current_sum += arr[i];
        }
    }

    return 1;  // Successfully allocated to m or fewer students
}

// Find minimum possible maximum pages using binary search
int minimize_max_pages(int arr[], int n, int m) {
    // If more students than books, allocation not possible
    if (m > n) {
        return -1;
    }

    int low = find_max(arr, n);     // At least the largest book
    int high = find_sum(arr, n);    // At most all books to one student
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (can_allocate(arr, n, m, mid)) {
            result = mid;            // This max is feasible
            high = mid - 1;          // Try to minimize further
        } else {
            low = mid + 1;           // Need more pages per student
        }
    }

    return result;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minimize_max_pages(arr, n, m));

    return 0;
}