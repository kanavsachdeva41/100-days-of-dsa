/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO */
#include <stdio.h>

int hasCycle(int v, int parent, int n, int adj[n][n], int visited[]) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (hasCycle(i, v, n, adj, visited))
                    return 1;
            }
            else if (i != parent) {
                return 1; // Cycle found
            }
        }
    }

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

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int cycle = 0;

    // Check all connected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycle(i, -1, n, adj, visited)) {
                cycle = 1;
                break;
            }
        }
    }

    printf(cycle ? "YES\n" : "NO\n");

    return 0;
}