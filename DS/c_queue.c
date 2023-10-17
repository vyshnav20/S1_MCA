#include <stdio.h>
int MAX = 10, rear = -1, front = -1;
int a[10];

void Enqueue()
{
    int val;

    if (((rear + 1) % MAX == front))
    {
        printf("\n QUEUE OVERFLOW!!!");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == MAX - 1 && front != 0)
        {
            rear = 0;
        }
        else
            rear = (rear + 1) % MAX;
        printf("\n Enter value to be inserted: ");
        scanf("%d", &val);
        a[rear] = val;
        printf("\n %d inserted to the queue", val);
    }
}

void Dequeue()
{
    if (front == -1)
        printf("\n QUEUE UNDERFLOW!!!");
    else
    {
        int v = a[front];
        if (front == rear)
            front = rear = -1;
        else if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
        printf("\n Removed Element: %d", v);
    }
}

int peek()
{
    printf("\n Element in rear position of queue is %d", a[rear]);
    printf("\n Element in front position of queue is %d", a[front]);
}

void display()
{
    if (rear == -1)
        printf("\n QUEUE EMPTY!!!!");
    else
    {
        printf("\n QUEUE ELEMENTS: ");
        if (front <= rear)
            for (int i = front; i <= rear; i++)
                printf("%d ", a[i]);
        else
        {
            for (int i = 0; i <= rear; i++)
                printf("%d ", a[i]);
            for (int i = front; i < MAX; i++)
                printf("%d ", a[i]);
        }
    }
}

void main()
{
    printf("Enter max size of queue: ");
    scanf("%d", &MAX);
    int ch = 4;
    do
    {
        printf("\n\n-----------------------------------------------------\n 1: Insertion\n 2: Deletion\n 3: Queue Display\n 4: Peek\n 5: Exit\n-----------------------------------------------------\n Enter your choice: ");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        }
    } while (ch < 5);
}
