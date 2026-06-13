/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>

int hasCycle(int v, int n, int adj[n][n], int visited[], int recStack[]) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (hasCycle(i, n, adj, visited, recStack))
                    return 1;
            }
            else if (recStack[i]) {
                return 1; // Back edge found => cycle
            }
        }
    }

    recStack[v] = 0;
    return 0;
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

    int visited[n], recStack[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int cycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycle(i, n, adj, visited, recStack)) {
                cycle = 1;
                break;
            }
        }
    }

    printf(cycle ? "YES\n" : "NO\n");

    return 0;
}