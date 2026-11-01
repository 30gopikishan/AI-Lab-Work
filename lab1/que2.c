//dfs
#include <stdio.h>

#define MAX 10

int visited[MAX];   // Track visited nodes
int graph[MAX][MAX]; // Adjacency matrix
int n;              // Number of vertices

// Recursive DFS function
void dfs(int v) {
    visited[v] = 1; // Mark current node as visited
    printf("%d ", v);

    // Explore all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    // Example graph with 5 vertices
    n = 5;
    int adj[5][5] = 
    {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,1},
        {0,0,1,1,0}
    };

    // Copy adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = adj[i][j];

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal starting from node 0:\n");
    dfs(0);

    return 0;
}
