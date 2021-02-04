#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node *insert(struct node*,int*);
void print(struct node*,int);
void search(struct node*,int);
struct node *root=0;
int loc=0;
int main()
{
    int size,x,y;
    printf("Enter the size of the tree:");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        scanf("%d",&x);
        root=insert(root,&x);
        printf("Data %d inserted..!\n",x);
    }
    printf("Enter data to be searched:");
    scanf("%d",&y);
    print(root,y);
    search(root,y);
    return 0;
}
struct node* insert(struct node*root,int* data)
{
    if(root==NULL)
    {
        struct node* newnode=(struct node *)malloc(sizeof(struct node));
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
            printf("Tree can not have duplicate data.");
    }
    return root;
}
void search(struct node* root,int y)
{
    static int flag;
    if(y==root->data)
    {
        printf("\nYes,data is present in tree at %d position...",loc+1);
        flag=1;
        return;
    }
    else if(y<root->data)
        search(root->left,y);
    else
        search(root->right,y);
    if(flag==0)
        printf("Data is not present in tree...!");
}
void print(struct node* root,int y)
{
    if(root==NULL)
        return;
    else
    {
        print(root->left,y);
        printf("%d ",root->data);
        if(root->data<y)
            loc++;
        print(root->right,y);
    }
}

