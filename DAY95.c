// Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
// Distribute into buckets, sort each, concatenate.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    float data;
    struct Node *next;
} Node;

void insertSorted(Node **head, float value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *curr = *head;
    while (curr->next != NULL && curr->next->data < value)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;
}

void bucketSort(float arr[], int n)
{
    Node *buckets[n];

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Distribute elements into buckets
    for (int i = 0; i < n; i++)
    {
        int index = (int)(arr[i] * n);
        insertSorted(&buckets[index], arr[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        Node *curr = buckets[i];
        while (curr != NULL)
        {
            arr[k++] = curr->data;
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}