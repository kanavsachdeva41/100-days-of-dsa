//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int adj[n][n];
    int indegree[n];

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j];

            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    int queue[n];
    int front = 0, rear = 0;

    // Enqueue all vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;

                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    // Optional: Detect cycle
    if (count != n)
        printf("\nGraph contains a cycle!");

    return 0;
}