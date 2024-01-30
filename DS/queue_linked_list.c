#include<stdio.h>
#include<stdlib.h>

struct node {
    int d;
    struct node *next;
}*head,*temp,*cur;

int max,c=0;


void enqueue(int v)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->d=v;
    newnode->next=NULL;
    if(head==NULL) 
    {
            head=newnode;
            c++;
    }
    else if(c==max)
    {
        printf("\nQueue OVERFLOW!!!\n");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        c++;

    }
    
}


int dequeue()
{
    if(c==0)
        printf("\nQueue EMPTY!!!\n");
    else
    {
        temp=head;
        head=head->next;
        c--;
        printf("%d is deleted ",temp->d);
        return temp->d;
    }
}


void display(){
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->d);
        temp=temp->next;
    }
}

void main()
{
    printf("Enter size of stack: ");
    scanf("%d",&max);
    int ch,n;
    do
    {
        printf("\n1: Enqueue\n2: Dequeue\n3:Display\n4:Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d",&n);
            enqueue(n);
            break;
        case 2:
            int v=dequeue();break;
        case 3:
            printf("\nQueue: ");
            display();break;
        }
    } while (ch<4);
    
}