#include <stdio.h>
#include <stdlib.h>
int MAX = 10, rear = -1, front = -1;
int a[10];
void Enqueue(int n)
{
    int val;
    
    if (rear == MAX - 1)
        return;
    if (rear == -1)
            front = 0;
    rear++;
    a[rear] = n;
    }


int Dequeue()
{
    if (front == -1)
        return -1;
    int v = a[front];
    front++;
    return v;

}

int cycle(int u,int v,int n,int a[n][n])
{
    int v1[n];
    for (int i = 0; i < n; i++)
        v1[i] = 0;
    int start=u,c=0;
    Enqueue(start);
    v1[start]=1;
    while(front<=rear)
    {
        start=Dequeue();
        for(int i=0; i<n;i++)
            if(a[start][i]==1 && v1[i]==0)
            {
                Enqueue(i);
                v1[i]=1;
                if(i==v)
                {
                    c=1;
                    break;
                }
            }
    }
    if(c==1)
        return 1;
    else
        return 0;

}

void main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int A[n][n], a[n][n], cost = 0, u, v, min = 999, e = 1;
    printf("Enter the cost adjacency matrix of the graph: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            
            scanf("%d", &A[i][j]);
            if (A[i][j] == 0)
                A[i][j] = 999;
            a[i][j]=0;
        }
    
    printf("\n Minimum cost spanning tree:\n");
    while (e <n)
    {
        min = 999;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] < min)
                {
                    
                        min = A[i][j];
                        u = i;
                        v = j;
                    
                }
            }
        }
        //cycle functions checks if adding the edge u,v creates a cycle using bfs.
        if(cycle(u,v,n,a)==0)
        {
            cost += min;
            A[u][v] = 999;
            A[v][u] = 999;
            e += 1;
            printf("Edge {%d,%d} = %d \n", u,v, min);
            a[u][v]=1;
            a[v][u]=1;
            front=-1;
            rear=-1;
        }
        else{
            A[u][v] = 999;
            A[v][u] = 999;            
            front=-1;
            rear=-1;
        }
    }
    printf("Minimum Cost: %d\n", cost);
}
