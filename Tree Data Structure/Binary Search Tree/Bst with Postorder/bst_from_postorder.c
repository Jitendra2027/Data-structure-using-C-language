#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node *root=0;
struct node *create(struct node*,int *);
void print(struct node*);
int main()
{
    int size;
    printf("Enter the size of the tree:");
    scanf("%d",&size);
    int postorder[size];
    printf("Enter postorder of the tree:");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&postorder[i]);
    }
    //root will be at the end in postorder traversal
    for(int i=size-1;i>=0;i--)
    {
        root=create(root,&postorder[i]);
        printf("%d inserted in tree\n",postorder[i]);//insertion in tree
    }
    //Preorder printing of the tree
    printf("Preorder traversal of the tree created: ");
    print(root);
    return 0;
}
struct node* create(struct node* root,int *data)
{
    if(root==NULL)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=*data;
        newnode->left=0;
        newnode->right=0;
        return newnode;
    }
    if(root->data>*data)
        root->left=create(root->left,data);
    if(root->data<*data)
        root->right=create(root->right,data);
    return root;
}
void print(struct node* root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    print(root->left);
    print(root->right);
}

