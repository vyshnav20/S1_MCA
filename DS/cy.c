#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5

int isCyclicUtil(int graph[MAX_NODES][MAX_NODES], int visited[MAX_NODES], int stack[MAX_NODES], int node, int numNodes) {
    if (!visited[node]) {
        visited[node] = 1;
        stack[node] = 1;

        for (int i = 0; i < numNodes; i++) {
            if (graph[node][i]) {
                if (!visited[i] && isCyclicUtil(graph, visited, stack, i, numNodes)) {
                    return 1;
                } else if (stack[i]) {
                    return 1;
                }
            }
        }
    }

    stack[node] = 0;
    return 0;
}

int isCyclic(int n,int graph[n][n] ) {
    int visited[MAX_NODES] = {0};
    int stack[MAX_NODES] = {0};

    for (int i = 0; i < n; i++) {
        if (isCyclicUtil(graph, visited, stack, i, n)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);

    int graph[n][n];
    for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
			scanf("%d",&graph[i][j]);
	}
    if (isCyclic(graph, n)) {
        printf("The directed graph contains a cycle.\n");
    } else {
        printf("The directed graph does not contain a cycle.\n");
    }

    return 0;
}
