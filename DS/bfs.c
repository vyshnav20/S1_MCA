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

void main()
{
    int n, start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int a[n][n], v[n];
    printf("Enter Adjacency matrix for the graph: ");
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    printf("Enter starting node (0-%d): ", (n - 1));
    scanf("%d", &start);
    printf("\nBFS Traversal: ");
    Enqueue(start);
    v[start]=1;
    while(front<=rear)
    {
        start=Dequeue();
        printf("%d ",start);
        for(int i=0; i<n;i++)
            if(a[start][i]==1 && v[i]==0)
            {
                Enqueue(i);
                v[i]=1;
            }
    }
}