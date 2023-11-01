#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root;
struct node *addNode()
{
    struct node *new=(struct node *)malloc(sizeof(struct node);
    printf("Enter value to new node: ");
    scanf("%d",&new->data);
    new->left=NULL;
    new->left=NULL;
    return new;
}
struct node *insert(struct node *root,struct node *new)
{
    if(root==NULL)
        return new;
    else
    {
        if(new->data > root->data)
            root->right=insert(root->right,new);
        else
            root->left=insert(root->left,new);
    }
    return root;
}
void traverse(struct node *root)
{
    if (root==NULL)
        printf("Tree Empty");
    else
    {
        traverse(root->left);
        print("%d ",root->data);
        traverse(root->right);
    }
}
void main()
{
    int n;
    printf("Enter number of nodes in tree: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
            struct node *new=addNoded();
            root=insert(root,new);
        }
    traverse(root);
}
