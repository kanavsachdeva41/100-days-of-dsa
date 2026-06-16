/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include <stdio.h>
#include <limits.h>

#define MAX 101

int graph[MAX][MAX];
int n, m;

int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int selected[MAX] = {0};
    int key[MAX];

    for(int i = 1; i <= n; i++)
    {
        key[i] = INT_MAX;
    }

    key[1] = 0; // Start from vertex 1

    int mstWeight = 0;

    for(int count = 1; count <= n; count++)
    {
        int u = -1;
        int minKey = INT_MAX;

        for(int v = 1; v <= n; v++)
        {
            if(!selected[v] && key[v] < minKey)
            {
                minKey = key[v];
                u = v;
            }
        }

        selected[u] = 1;
        mstWeight += key[u];

        for(int v = 1; v <= n; v++)
        {
            if(graph[u][v] != INT_MAX &&
               !selected[v] &&
               graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", mstWeight);

    return 0;
}