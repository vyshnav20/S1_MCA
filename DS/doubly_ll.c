#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *last;
} *head, *temp, *prev, *tail,*curr;
int c=-1;
struct node *addnode()
{
    int v;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter value for new node: ");
    scanf("%d", &v);
    new_node->data = v;
    new_node->next = NULL;
    new_node->last = NULL;
    return new_node;
}
void insertBegining()
{
    struct node *new = addnode();
    if (head == NULL)
    {
        head = new;
        tail = new;
    }

    else
    {
        new->next = head;
        head->last = new;
        tail = head;
        head = new;
        printf("\nNODE ADDED!!! ");
    }
    c++;
}

void insertEnd()
{
    struct node *new = addnode();
    if (head == NULL)
    {
        head = new;
        tail = new;
    }
    else
    {
        tail->next = new;
        new->last = tail;
        tail = new;
        printf("\n NODE ADDED!!! ");
    }
    c++;
}

void insertPos()
{
    struct node *new = addnode();
    int pos;
    printf("Enter position to add node: ");
    scanf("%d", &pos);
    if(pos==0 && head!=NULL)
    {
        head->last=new;
        new->next=head;
        head=new;
        printf("\n NODE ADDED!!! ");
    }
    else if(pos>c)
    {
        printf("INVALID POSITION");
    }
    else
    {
        if (head == NULL)
        {
            head = new;
            tail = new;
            printf("\n NODE ADDED!!! ");
        }
        else
        {
            temp = head;
            pos--;
            for (int i = 0; i <pos; i++)
            {
                temp = temp->next;
            }
            new->next = temp->next;
            temp->next = new;
            new->last = temp;
            new->next->last = new;
            if (new->next == NULL)
                tail = new;
            printf("\n NODE ADDED!!! ");
        }
    }
    c++;
}

void delBegining()
{
    temp = head;
    if(head==NULL)
    {
      printf ("Linked List Empty, nothing to delete\n");
      return;
    }
    head=head->next;
    head->last=NULL;
    printf("\n %d is deleted from linked list!!!", temp->data);
    free(temp);
    if(head->next==NULL)
        tail=head;
    c--;
}

void delEnd()
{
    
    if(head==NULL)
    {
      printf ("Linked List Empty, nothing to delete\n");
      return;
    }
    temp=tail;
    tail=tail->last;    
    tail->next=NULL;
    printf("\n %d is deleted from linked list!!!", temp->data);
    free(temp);
    c--;
}

void delPos()
{
    if(head==NULL)
        printf("\n Linked List Empty");
    else
    {
    temp = head;
    int pos,k=0;
    printf("Enter position to delete node: ");
    scanf("%d", &pos);
    if(pos==0)
        delBegining();
    else if(pos==c)
        delEnd();
    else if (pos>c)
    {
        printf("INVALID POSITION");
        return;
    }
    else
    {   while(k!=pos)
        {            
            temp=temp->next;
            k++;
        }
        temp->last->next=temp->next;
        temp->next->last=temp->last;
        printf("\n %d is deleted from linked list!!!", temp->data);
        free(temp);
    }
    c--;
    }
}

void search()
{
    if(head==NULL)
        printf("\n Linked List Empty");
    else
    {
    temp = head;
    int s, pos = 1, c = 0;
    printf("\n Enter number to be searched: ");
    scanf("%d", &s);
    while (temp != NULL)
    {
        if (temp->data == s)
        {
            c = 1;
            break;
        }
        pos++;
        temp = temp->next;
    }
    if (c == 1)
        printf("\n%d is present in position %d of the linked list", s, pos);
    else
        printf("\n%d is not found in the linked list ", s);
}
}

void traverse()
{
    if(head==NULL)
        printf("\n Linked List Empty");
    else
    {
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    }
}

void display_reverse()
{
    if(head==NULL)
        printf("\n Linked List Empty");
    else
    {
    temp = tail;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->last;
    }
    }
}

void insertion()
{
    int ch;
    printf("\n\n-----------------------------------------------------\n 1: Insertion in Begining\n 2: Insertion at End\n 3: Insertion in a Position\n 4: Exit\n\n-----------------------------------------------------\n Enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        insertBegining();
        break;
    case 2:
        insertEnd();
        break;
    case 3:
        insertPos();
        break;
    }
}

void deletion()
{
    int ch;
    printf("\n\n-----------------------------------------------------\n 1: Deletion from Begining\n 2: Deletion at End\n 3: Deletion from a Position\n 4: Exit\n\n-----------------------------------------------------\n Enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        delBegining();
        break;
    case 2:
        delEnd();
        break;
    case 3:
        delPos();
        break;
    }
}
void main()
{
    int ch;
    do
    {
        printf("\n\n-----------------------------------------------------\n 1: Insertion\n 2: Deletion \n 3: Display Linked List\n 4: Display Linked List in reverse order\n 5: Search Elements\n 6: Exit\n\n-----------------------------------------------------\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            traverse();
            break;
        case 4:
            display_reverse();
            break;
        case 5:
            search();
            break;
        }
    } while (ch < 6);
}