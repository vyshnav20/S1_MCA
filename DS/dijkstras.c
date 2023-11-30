#include <stdio.h>
#include <stdlib.h>
int c = 0;
void fn(int n, int A[n][n], int V[], int D[], int start, int u)
{
    V[start] = 1;
    D[start] = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[u][i] != 999)
        {
            V[i] = 1;
            if ((D[u] + A[u][i]) < D[i])
                D[i] = D[u] + A[u][i];
        }
    }
    c++;
    if (c != 2)
        fn(n, A, V, D, start, 1);
}

void main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int A[n][n], V[n], D[n], N[n], u, v, start;
    for (int i = 0; i < n; i++)
    {
        V[i] = 0;
        N[i] = i;
        D[i] = 999;
    }
    printf("Enter the cost adjacency matrix of the graph: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
            if (A[i][j] == 0)
                A[i][j] = 999;
        }
    printf("Enter starting node: ");
    scanf("%d", &start);
    fn(n, A, V, D, start, start);
    for (int i = 0; i < n; i++)
        printf("%d ", D[i]);
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
}