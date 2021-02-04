#include<stdio.h>
#define MAX 40
int stack[MAX];
int top=-1;
int postIndex;
void push(int val)
{
        stack[++top]=val;
}
void printStack(int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",stack[i]);
}
int search(int a[],int x,int n)
{
    for(int i=0;i<n;i++)
        if(a[i]==x)
            return i;
    return -1;
}
void printPreOrder(int in[],int post[],int start,int end,int n)
{
    if(start>end)
        return;
    int val=post[postIndex];
    int inIndex=search(in,val,n);
    postIndex--;
    //push right subtree in the stack
    printPreOrder(in,post,inIndex+1,end,n);
    //push left subtree in the stack
    printPreOrder(in,post,start,inIndex-1,n);
    printf("%d ",val);
    push(val);
}
int main()
{
    int n;
    printf("Enter the number of nodes in the tree:");
    scanf("%d",&n);
    int post[]={4,5,2,6,3,1};
    int in[]={4,2,5,1,3,6};
    int postIndex=n-1;
    /*printf("Enter inorder traversal:");
    for(int i=0;i<n;i++)
        scanf("%d",&in[i]);
    printf("Enter postorder traversal:");
    for(int i=0;i<n;i++)
        scanf("%d",&post[i]);
    printPreOrder(in,post,0,postIndex,n);*/
    printf("Preorder traversal is:");
    printStack(n);
    return 0;
}
