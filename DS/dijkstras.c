#include <stdio.h>
#include <stdlib.h>
void fn(int n, int A[n][n], int V[], int D[], int start, int u)
{
   V[start] = 1;
    V[u]=1;
    D[start] = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[u][i] != 0)
        {
            
            if ((D[u] + A[u][i]) < D[i])
                D[i] = D[u] + A[u][i];
        }
    }
    int min =999;
    int pos=-1;
    for (int i=0; i<n;i++)
    {
        if(V[i]==0 && D[i]<min)
        {
            min=D[i];
            pos=i;
        }
    }
    if(pos!=-1)
        fn(n, A, V, D, start, pos);
            
 }
        
    
        

void main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int A[n][n], V[n], D[n], u, v, start;
    for (int i = 0; i < n; i++)
    {
        V[i] = 0;
        D[i] = 999;
    }
    printf("Enter the cost adjacency matrix of the graph: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    printf("Enter starting node: ");
    scanf("%d", &start);
    fn(n, A, V, D, start, start);
    for (int i = 0; i < n; i++)
        printf("%d ", D[i]);
}
