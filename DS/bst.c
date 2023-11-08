#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root, *temp;
struct node *addNode()
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("Enter value to new node: ");
    scanf("%d", &new->data);
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node *insert(struct node *root, struct node *new)
{
    if (root == NULL)
        return new;

    if (new->data > root->data)
        root->right = insert(root->right, new);
    else
        root->left = insert(root->left, new);

    return root;
}

struct node *inorder_successor(struct node *node)
{
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

struct node *delete(struct node *root, int val)
{
    if (root == NULL)
        return root;
    if (val > root->data)
        root->right = delete (root->right, val);
    else if (val < root->data)
        root->left = delete (root->left, val);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = inorder_successor(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}

void search(struct node *root, int v)
{
    if (root == NULL)
        printf("%d is not a node in the tree.\n", v);
    else
    {
        if (v == root->data)
            printf("%d is present in the tree.\n", v);
        else if (v < root->data)
            search(root->left, v);
        else
            search(root->right, v);
    }
}

void in_traverse(struct node *root)
{

    if (root != NULL)
    {
        in_traverse(root->left);
        printf("%d ", root->data);
        in_traverse(root->right);
    }
}
void pre_traverse(struct node *root)
{

    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_traverse(root->left);
        pre_traverse(root->right);
    }
}
void post_traverse(struct node *root)
{

    if (root != NULL)
    {
        post_traverse(root->left);
        post_traverse(root->right);
        printf("%d ", root->data);
    }
}
void traversal(struct node *root)
{
    int n;
    printf("\n----------------\n 1: Inorder Traversal\n 2: Preorder Traversal\n 3: Postorder Traversal\n----------------\n Enter your choice: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("Inorder Traversal : ");
        in_traverse(root);
        printf("\n");
        break;

    case 2:

        printf("Preorder Traversal : ");
        pre_traverse(root);
        printf("\n");
        break;

    case 3:
        printf("Postorder Traversal : ");
        post_traverse(root);
        printf("\n");
        break;
    }
}
void main()
{
    int n, v;
    do
    {
        printf("\n----------------\n 1: Insertion\n 2: Deletion\n 3: Traversal\n 4: Search\n 5: Exit\n----------------\n Enter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            root = insert(root, addNode());
            printf("\n NODE ADDED!!! ");
            break;

        case 2:

            printf("\n Enter value of node to be deleted: ");
            scanf("%d", &v);
            root = delete (root, v);
            printf("\n NODE DELETED!!! ");
            break;

        case 3:
            traversal(root);
            break;

        case 4:
            printf("\n Enter value of node to be searched: ");
            scanf("%d", &v);
            search(root, v);
            break;
        }
    } while (n < 5);
}
