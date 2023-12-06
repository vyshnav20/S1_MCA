#include <stdio.h>
#include <stdlib.h>

int dfs(int n,int node, int target,int graph[n][n],int visited[]) {
    visited[node] = 1;
    for(int i = 0; i < n; i++) {
        if(graph[node][i] == 1 && visited[i] == 0) {
            if(i == target) {
                return 1;
            }
            dfs(n,i, target,graph,visited);
        }
    }
}

void add_edge(int n,int u, int v,int graph[n][n]) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int A[n][n], N[n], cycle[n][n], V[n], cost = 0, u, v, min = 999, e = 1;
    
    for (int i = 0; i < n; i++)
    {
        V[i]=0;
        N[i] = i;
    }
    printf("Enter the cost adjacency matrix of the graph: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cycle[i][j] = 0;
            scanf("%d", &A[i][j]);
            if (A[i][j] == 0)
                A[i][j] = 999;
            if (A[i][j] < min)
            {
                min = A[i][j];
                u = i;
                v = j;
            }
        }
    cost += A[u][v];
    A[u][v]=999;
    A[v][u]=999;
    add_edge(n,u,v,cycle);
    printf("Edge {%d,%d} = %d \n", N[u], N[v], min);

    while (e < n-1) {
        min = 999;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] < min) {
                    min = A[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        
        if (dfs(n,u,v,cycle,V)==1) {
            A[u][v] = 999;
            A[v][u] = 999;
        } else {
            cost += A[u][v];
            A[u][v] = 999;
            A[v][u] = 999;
            e++;
            add_edge(n,u,v,cycle);
            printf("Edge {%d,%d} = %d \n", N[u], N[v], min);
        }
    }
    printf("Minimum Cost: %d\n", cost);
}
