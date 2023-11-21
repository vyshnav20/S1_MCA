#include <stdio.h>
#include <stdlib.h>
int MAX = 10, rear = -1, front = -1;
int a[10];
void Enqueue(int val, int V[], int c)
{
    if (rear == MAX - 1)
        printf("\n QUEUE OVERFLOW!!!");
    else
    {
        if (rear == -1)
            front = 0;
        rear++;
        a[rear] = val;
    }
    V[c] = 1;
}
void Dequeue(int n, int N[], int A[n][n], int V[])
{
    if (front == -1)
        printf("\n QUEUE UNDERFLOW!!!");
    else
    {
        int v = a[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
                if (A[0][j] == 1)
                    Enqueue(N[j], V, i + 1);
        }
}

void display()
{
    if (rear == -1)
        printf("\n QUEUE EMPTY!!!!");
    else
    {
        printf("\n QUEUE ELEMENTS: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", a[i]);
    }
}

void main()
{
    int n;
    int c = 0;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int A[n][n], V[n], N[n];
    for (int i = 0; i < n; i++)
    {
        V[i] = 0;
        N[i] = i + 1;
    }
    printf("Enter the cost adjacency matrix of the graph: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
            if (A[i][j] == 0)
                A[i][j] = 999;
        }
    Enqueue(N[0], V, c);

    Dequeue(n, N, A, V);
    display();
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
}