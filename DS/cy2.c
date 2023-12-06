#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 9

int graph[9][9];
int visited[9];

int dfs(int node, int target) {
    visited[node] = 1;
    for(int i = 0; i < MAX_NODES; i++) {
        if(graph[node][i] == 1 && visited[i] == 0) {
            if(i == target) {
                printf("A path exists from %d to %d\n", node, target);
                return 1;
            }
            dfs(i, target);
        }
    }
    return 0;
}

void add_edge(int u, int v) {
    if(dfs(u, v)==0)
    {graph[u][v] = 1;
    graph[v][u] = 1;}
    else{
        printf("not");
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
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    add_edge(0, 2);
    add_edge(0, 1); // a->z
    for(int i = 0; i < MAX_NODES; i++) {
        for(int j = 0; j < MAX_NODES; j++) 
            printf("%d ",graph[i][j]);
            printf("\n");
    }
    add_edge(1,2);
    

    return 0;

}
