#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
    int height;
};
struct node* root=NULL;
struct node* insert(struct node*,int);
struct node* deleteNode(struct node*,int);
void print(struct node*);
int height(struct node*);
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
struct node* leftRotate(struct node* x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}
struct node* rightRotate(struct node* y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}
struct node* minValue(struct node* node)
{
    struct node* current=node;
    while(current->left!=NULL)
        current=current->left;
    return current;
}
struct node* deleteNode(struct node* root,int key)
{
    if(root==NULL)
        return root;
    else if(root->data>key)
        root->left=deleteNode(root->left,key);
    else if(root->data<key)
        root->right=deleteNode(root->right,key);
    else
    {
        if(root==NULL)
            return root;
        if(key<root->data)
            root->left=deleteNode(root->left,key);
        else if(key>root->data)
            root->right=deleteNode(root->right,key);
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
    if(root==NULL)
        return root;
    root->height=1+height(root->left)>height(root->right)?height(root->left):height(root->right);
    int balance=root!=NULL?height(root->left)-height(root->right):0;
    if(balance>1 && root->left->data>key)
        rightRotate(root);
    if(balance>1 && root->left->data<key)
    {
        root->left=rightRotate(root->left);
        leftRotate(root);
    }
    if(balance<-1 && root->right->data<key)
        leftRotate(root);
    if(balance<-1 && root->right->data>key)
    {
        root->right=leftRotate(root->right);
        rightRotate(root);
    }
    return root;
}
int main()
{
    int x,flag;
    while(1)
    {
        printf("Enter item to be inserted in tree:");
        scanf("%d",&x);
        root=insert(root,x);
        printf("Enter 1 to continue and 0 to exit:");
        scanf("%d",&flag);
        if(flag==0)
            break;
    }
    printf("Inorder traversal of the tree before deletion is:");
    print(root);
    printf("\n");
    while(1)
    {
        printf("Enter item to be deleted:");
        scanf("%d",&x);
        deleteNode(root,x);
        printf("*****Item deleted from tree*****\n");
        printf("Inorder traversal of the tree after deletion is:");
        print(root);
        printf("\nEnter 1 to delete more node and 0 for exit:");
        scanf("%d",&flag);
        if(flag==0)
            break;
    }
    return 0;
}
struct node* insert(struct node* root,int data)
{
    if(root==NULL)
    {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->data   = data;
        node->left   = NULL;
        node->right  = NULL;
        node->height = 1;  // new node is initially added at leaf
        return(node);
    }
    if(root->data>data)
        root->left=insert(root->left,data);
    if(root->data<data)
        root->right=insert(root->right,data);
    else
        return root;
    root->height=height(root->left)>height(root->right)?height(root->left):height(root->right);
    int balance=root!=NULL?height(root->left)-height(root->right):0;
    if(balance>1 && root->left->data>data)
        rightRotate(root);
    if(balance>1 && root->left->data<data)
    {
        root->left=rightRotate(root->left);
        leftRotate(root);
    }
    if(balance<-1 && root->right->data<data)
        leftRotate(root);
    if(balance<-1 && root->right->data>data)
    {
        root->right=leftRotate(root->right);
        rightRotate(root);
    }
    return root;
}
void print(struct node* root)
{
    if(root==NULL)
        return;
    print(root->left);
    printf("%d ",root->data);
    print(root->right);
}

