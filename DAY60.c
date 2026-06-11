/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int isMinHeap = 1;

    for (int i = 0; i <= (N - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < N && arr[i] > arr[left]) {
            isMinHeap = 0;
            break;
        }

        if (right < N && arr[i] > arr[right]) {
            isMinHeap = 0;
            break;
        }
    }

    if (isMinHeap)
        printf("YES");
    else
        printf("NO");

    return 0;
}