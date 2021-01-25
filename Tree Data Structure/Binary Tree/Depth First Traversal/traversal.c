#include<stdio.h>
#include<stdlib.h>
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
struct node* create();
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=0;
int main()
{
    int choice,i;
    printf("\t\t\t\t\t*****Before Traversals we create a binary tree*****\n");
    root=create();
    do
    {
        printf("Enter your choice:");
        printf("1.INORDER TRAVERSAL\t 2.PREORDER TRAVERSAL\t 3.POSTORDER TRAVERSAL\t 4.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
            {
                case 1:
                        inorder(root);
                        break;
                case 2:
                        preorder(root);
                        break;
                case 3:
                        postorder(root);
                        break;
                case 4:
                        exit(1);
                        break;
                default:
                    printf("Enter a valid choice...!\n");
            }
    printf("Enter 1 to continue or 0 to exit:");
    scanf("%d",&i);
    }
    while(i!=0);
    return 0;
}
struct node* create()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data(enter -1 for no node):");
    scanf("%d",&newnode->data);
    if(newnode->data==-1)
        return 0;
    printf("Enter the left child of %d:----",newnode->data);
    newnode->left=create();
    printf("Enter the right child of %d:---",newnode->data);
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
void preorder(struct node *root)
{
    if(root==0)
        return ;
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root==0)
        return ;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
