#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node*insert(struct node *,int *);
void display(struct node *);
struct node *root=0;
int main()
{
    int size,x;
    printf("Enter the number of data:");
    scanf("%d",&size);
    printf("Enter the data to be inserted in BST:");
    for(int i=0;i<size;i++)
    {
            scanf("%d",&x);
            root=insert(root,&x);
            printf("Data %d inserted in BST...\n",x);
    }
    printf("Tree elements are:");
    display(root);
    return 0;
}
struct node* insert(struct node *root,int *data)
{
    if(root==0)
    {
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=*data;
        newnode->left=0;
        newnode->right=0;
        return newnode;
    }
    else
    {
        if(*data<root->data)
            root->left=insert(root->left,data);
        else if(*data>root->data)
            root->right=insert(root->right,data);
        else
            printf("Two or more data can not be same in BST...!\n");
    }
    return root;
}
//Inorder traversal:data will always be in sorted form.
void display(struct node *root)
{
    if(root==0)
        return;
    else
    {
        display(root->left);
        printf("%d ",root->data);
        display(root->right);
    }
}
