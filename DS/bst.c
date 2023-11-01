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
struct node *insert(struct node *root, struct node *new)
{
    if (root == NULL)
    {
        return new;
    }

    if (new->data > root->data)
        root->right = insert(root->right, new);
    else if (new->data <= root->data)
        root->left = insert(root->left, new);
    return root;
}

void traverse(struct node *root)
{
    if (root != NULL)
    {
        traverse(root->left);
        printf("%d", root->data);
        traverse(root->right);
    }
}
void main()
{
    struct node *root;
    for (int i = 0; i < 5; i++)
    {
        struct node *new1 = addnode();
        root = insert(root, new1);
    }
    traverse(root);
}