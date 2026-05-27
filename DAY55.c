/* Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue for building tree + BFS
struct Node* queue[MAX];
int front = 0, rear = 0;

void push(struct Node* node) {
    queue[rear++] = node;
}

struct Node* pop() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Create new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    push(root);

    int i = 1;

    while (!isEmpty() && i < n) {
        struct Node* curr = pop();

        // left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            push(curr->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            push(curr->right);
        }
        i++;
    }

    return root;
}

// Right view function
void rightView(struct Node* root) {
    if (!root) return;

    struct Node* q[MAX];
    int f = 0, r = 0;

    q[r++] = root;

    while (f < r) {
        int size = r - f;

        for (int i = 0; i < size; i++) {
            struct Node* node = q[f++];

            // last node of this level
            if (i == size - 1)
                printf("%d ", node->data);

            if (node->left) q[r++] = node->left;
            if (node->right) q[r++] = node->right;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}