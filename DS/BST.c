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
void insert(struct node *root)
{   
    struct node *new = addnode();
    printf("%d",new->data);
    if (root == NULL)
        root=new;
    else{

        if (new->data > root->data)
            insert(root->right);
        else if (new->data <= root->data)
            insert(root->left);
    }
}
void traverse(struct node *root)
{
    
    printf("%d",root->data);
}
    

void main()
{
    struct node *root;
    insert(root);
    traverse(root);
    


}