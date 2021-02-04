#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node *insert(struct node*,int *);
struct node *minValue(struct node*);
struct node* deleteNode(struct node*,int);
void print(struct node*);
struct node *root=0;
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
    printf("Before deleting node inorder traversal is:");
    print(root);
    printf("\nEnter data to be deleted:");
    scanf("%d",&y);
    root=deleteNode(root,y);
    printf("\nAfter deleting node inoreder traversal is:");
    print(root);
    return 0;
}
struct node* insert(struct node* root,int* data)
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
struct node* deleteNode(struct node *root,int y)
{
    if(root==NULL)
        return root;
    if(y<root->data)
        root->left=deleteNode(root->left,y);
    else if(y>root->data)
        root->right=deleteNode(root->right,y);
    else
    {
        if(root->left==NULL)
        {
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node* temp=root->left;
            free(root);
            return temp;
        }
        struct node* temp =minValue(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
}
struct node* minValue(struct node* node)
{
    struct node* current=node;
    while(current->left!=NULL)
        current=current->left;
    return current;
}
void print(struct node* root)
{
    if(root==NULL)
        return;
    else
    {
        print(root->left);
        printf("%d ",root->data);
        print(root->right);
    }
}

