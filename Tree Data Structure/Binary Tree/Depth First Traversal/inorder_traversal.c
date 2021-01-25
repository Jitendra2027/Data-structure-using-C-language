#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node* create();
void inorder(struct node *);
struct node *root;
int main()
{
    root=create();
    inorder(root);
    return 0;
}
struct node* create()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data(enter -1 for termination or no node):");
    scanf("%d",&newnode->data);
    if(newnode->data==-1)
        return 0;
    printf("Enter the left child of %d\n",newnode->data);
    newnode->left=create();
    printf("Enter the right child of %d\n",newnode->data);
    newnode->right=create();
    return newnode;
}
void inorder(struct node *root)
{
    if(root!=0)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    else
        return ;
}
