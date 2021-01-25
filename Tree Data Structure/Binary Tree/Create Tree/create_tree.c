#include<stdio.h>
#include<stdlib.h>
struct node* create();
void display(struct node *);
struct node
{
    int data;
    struct node *left,*right;
};
int main()
{
    struct node *root;
    root=0;
    root=create();
    display(root);
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
void display(struct node *root)
{
    if(root!=0)
    {
        printf("%d ",root->data);
        display(root->left);
        display(root->right);
    }
}
