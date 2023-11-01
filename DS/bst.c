#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *addnode()
{
    int v;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter value for new node: ");
    scanf("%d", &v);
    new_node->data = v;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void insert(struct node *root, struct node *new)
{
    if (root == NULL)
    {
        root = new;
        printf("%d", root->data);
    }

    else
    {
        if (new->data > root->data)
            insert(root->right, new);
        else if (new->data <= root->data)
            insert(root->left, new);
        if (new->data > root->data)
            root->right = new;
        else
            root->left = new;
    }
}
void traverse(struct node *root)
{
    printf("%d", root->data);
    printf("%d", root->right->data);
}
void main()
{
    struct node *new1 = addnode();
    struct node *root;
    insert(root, new1);
    struct node *new2 = addnode();
    insert(root, new2);
    traverse(root);
    
}