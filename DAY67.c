//Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>

void topologicalSortUtil(int v, int n, int adj[n][n], int visited[], int stack[], int *top) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            topologicalSortUtil(i, n, adj, visited, stack, top);
        }
    }

    stack[++(*top)] = v;
}

int main() {
    int n;
    scanf("%d", &n);

    int adj[n][n];

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int visited[n];
    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, n, adj, visited, stack, &top);
        }
    }

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}