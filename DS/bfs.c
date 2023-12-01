#include <stdio.h>
#include <stdlib.h>
int MAX = 10, rear = -1, front = -1;
int q[10],child[10],cno=0;
void Enqueue(int si, int a[si][si], int v[]);
void display()
{
    if (rear == -1)
        printf("\n QUEUE EMPTY!!!!");
    else
    {
        printf("\n QUEUE ELEMENTS: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", q[i]);
    }
}
void Dequeue(int si, int a[si][si], int v[])
{
    int val;
    if (front == -1)
        printf("\n Empty");
    else
    {
        val = q[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }        
        int k=0;
        cno=0;
        for (int i = 0; i < si; i++)
        {
            if (a[val][i] == 1 && v[i] != 1)
            {
                child[k++]=i;
                cno+=1;
            }  
        }
        
        Enqueue(si, a, v);
    }
}

void Enqueue(int si, int a[si][si], int v[])
{
    
    for(int i=0;i<cno;i++)
    {
        if (v[child[i]] != 1)
    {
        if (rear == -1)
            front = 0;
        rear++;
        q[rear] = child[i];
        printf("%d ", child[i]);
        v[child[i]] = 1;        
    }
    }
    for (int i = 0; i < si; i++)
        {
            if (a[q[front]][i] == 1 && v[i] != 1)
                Dequeue(si, a, v);
        }
    
    
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
    printf("\nDFS Traversal: ");
    child[0]=start;
    cno=1;
    Enqueue(n, a, v);
}