/* Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10 */
#include <stdio.h>
#define MAX 100

int main() {
    int n, i;

    // Input size
    scanf("%d", &n);

    int queue[MAX], stack[MAX];
    int front = 0, rear = n - 1;
    int top = -1;

    // Input queue elements
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Step 1: Push queue elements into stack
    for(i = front; i <= rear; i++) {
        stack[++top] = queue[i];
    }

    // Step 2: Pop from stack back to queue
    for(i = front; i <= rear; i++) {
        queue[i] = stack[top--];
    }

    // Output reversed queue
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}