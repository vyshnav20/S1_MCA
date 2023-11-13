#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head, *temp, *prev,*curr;
int c=-1;
struct node *addnode()
{
    int v;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter value for new node: ");
    scanf("%d", &v);
    new_node->data = v;
    new_node->next = NULL;
    return new_node;
}
void insertBegining()
{
    struct node *new = addnode();
    if (head == NULL)
    {
        head = new;
        new->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        new->next = head;
        temp->next = new;
        head = new;
    }
    printf("\n NODE ADDED!!! ");
    c++;
}
void insertEnd()
{
    struct node *new = addnode();
    if (head == NULL)
    {
        head = new;
        head->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = head;
        
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
        temp=head;
        while (temp->next != head)
            temp = temp->next;
        new->next = head;
        temp->next = new;
        head = new;
        printf("\n NODE ADDED!!! ");
    }
    else if (pos>c)
    {
        printf("INVALID POSITION");
        return;
    }
    else if (head == NULL)
    {
        head = new;
        head->next = head;
        printf("\n NODE ADDED!!! ");
    }
    else if(pos==c-1)
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = head;
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
        printf("\n NODE ADDED!!! ");
    }
    c++;
}

void delBegining()
{
    temp = head;
    if (head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }
    if (temp->next == head)
    {
      head = NULL;
      return;
    }
    curr=head;
    printf("\n %d is deleted from linked list!!!", temp->data);
    while (curr->next != head)
        {
            curr = curr->next;
        }
    curr->next=head->next;
    head = head->next;
    free(temp);
    c--;
}

void delEnd()
{
    temp = head;
    if (head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }
    if (temp->next == head)
    {
      head = NULL;
      return;
    }
    
    
    while (temp->next != head)
        {
            prev=temp;
            temp = temp->next;
        }
    prev->next=head;
    printf("\n %d is deleted from linked list!!!", temp->data);
    free(temp);
    c--;
}

void delPos()
{
    temp = head;
    int pos,k=0;
    printf("Enter position to add node: ");
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
    {        
        while(k!=pos)
        {            
            prev=temp;
            temp=temp->next;
            k++;
        }
        prev->next=temp->next;
        printf("\n %d is deleted from linked list!!!", temp->data);
        free(temp);
    }
    
    c--;
}

void search()
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

void traverse()
{
    temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
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
        printf("\n\n-----------------------------------------------------\n 1: Insertion\n 2: Deletion \n 3: Display Linked List\n 4: Search Elements\n 5: Exit\n\n-----------------------------------------------------\n Enter your choice: ");
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
            search();
            break;
        }
    } while (ch < 5);
}