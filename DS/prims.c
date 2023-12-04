#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int A[n][n], V[n], N[n], cost = 0, u, v, min = 999, e = 1;
    for (int i = 0; i < n; i++)
    {
        V[i] = 0;
        N[i] = i;
    }
    printf("Enter the cost adjacency matrix of the graph: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
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
    V[u] = 1;
    V[v] = 1;
    cost += A[u][v];
    printf("Edge {%d,%d} = %d \n", N[u], N[v], min);
    while (e < n - 1)
    {
        min = 999;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (V[i] == 1)
                {
                    if (A[i][j] < min && V[j] != 1)
                    {
                            min = A[i][j];
                            u = i;
                            v = j;
                        
                    }
                }
            }
        }
        cost += min;
        e += 1;
        V[v] = 1;
        printf("Edge {%d,%d} = %d \n", N[u], N[v], min);
    }
    printf("Minimum Cost: %d\n", cost);
}