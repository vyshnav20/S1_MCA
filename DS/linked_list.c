#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head, *temp, *prev;
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
        head = new;
    else
    {
        new->next = head;
        head = new;
        printf("\nNODE ADDED!!! ");
    }
}
void insertEnd()
{
    struct node *new = addnode();
    if (head == NULL)
        head = new;
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        printf("\n NODE ADDED!!! ");
    }
}

void insertPos()
{
    struct node *new = addnode();
    int pos;
    printf("Enter position to add node: ");
    scanf("%d", &pos);
    pos--;
    if (head == NULL)
        head = new;
    else
    {
        temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
        printf("\n NODE ADDED!!! ");
    }
}

void delBegining()
{
    temp = head;
    printf("\n %d is deleted from linked list!!!", temp->data);
    head = head->next;
    free(temp);
}

void delEnd()
{
    temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("\n %d is deleted from linked list!!!", temp->data);
    free(temp);
}

void delPos()
{
    temp = head;
    int pos;
    printf("Enter position to add node: ");
    scanf("%d", &pos);
    pos--;
    for (int i = 1; i <= pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    printf("\n %d is deleted from linked list!!!", temp->data);
    free(temp);
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
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void main()
{
    int ch;
    do
    {
        printf("\n\n-----------------------------------------------------\n 1: Insertion in Begining\n 2: Insertion at End\n 3: Insertion in a Position\n 4: Deletion from Begining\n 5: Deletion at End\n 6: Deletion from a Position\n 7: Display Array\n 8: Search Elements\n 9: Exit\n\n-----------------------------------------------------\n Enter your choice: ");
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
        case 4:
            delBegining();
            break;
        case 5:
            delEnd();
            break;
        case 6:
            delPos();
            break;
        case 7:
            traverse();
            break;
        case 8:
            search();
            break;
        }
    } while (ch < 9);
}