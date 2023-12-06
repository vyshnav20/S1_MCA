#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 9

int graph[9][9];
int visited[9];

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void dfs(int node, int target) {
    visited[node] = 1;
    for(int i = 0; i < MAX_NODES; i++) {
        if(graph[node][i] == 1 && visited[i] == 0) {
            if(i == target) {
                printf("A path exists from %d to %d\n", node, target);
                exit(0);
            }
            dfs(i, target);
        }
    }
}

int main() {
    // Initialize graph and visited array
    for(int i = 0; i < MAX_NODES; i++) {
        for(int j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Add edges
    add_edge(0, 1); // a->z
    add_edge(1, 0); // z->a
    add_edge(2, 2); // b->y
    add_edge(2, 2); // y->b
    add_edge(1, 3); // z->y
    add_edge(3, 1); // y->z

    // Check if a path exists from '0' to '2'
    dfs(0, 3);

    printf("No path exists from '0' to '2'\n");
    return 0;
}
