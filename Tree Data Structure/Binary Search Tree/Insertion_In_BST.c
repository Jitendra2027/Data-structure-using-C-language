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
    int array[20];
    int size;
    printf("Enter the number of data:");
    scanf("%d",&size);
    printf("Enter the data to be inserted in BST:");
    for(int i=0;i<size;i++)
    {
            scanf("%d",&array[i]);
            root=insert(root,&array[i]);
            printf("Data %d inserted in BST...\n",array[i]);
    }
    printf("Tree elements are:");
    display(struct node *root);
    return 0;
}
struct node* insert(struct node *root,int *data)
{
    if(root==0)
    {
        struct node *current,*newnode;
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
            printf("Enter a valid data for insertion...!\n");
    }
    return root;
}
//preorder traversal
void display(struct node *root)
{
    printf("dj");
    if(root==0)
        return ;
    else
    {
        printf("%d ",root->data);
        display(root->left);
        display(root->right);
    }
}
