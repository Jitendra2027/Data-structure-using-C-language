#include<stdio.h>
int search(int a[],int x,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
            return i;
    }
    return -1;
}
void postorder(int in[],int pre[],int n)
{
    int root=search(in,pre[0],n);
    if(root!=0)
        postorder(in,pre+1,root);
    if(root!=n-1)
    {
        postorder(in+root+1,pre+root+1,n-root-1);
    }
    printf("%d ",pre[0]);
}
int main()
{
    int n;
    printf("Enter the number of nodes of the tree:");
    scanf("%d",&n);
    int pre[n],in[n];
    printf("Enter Preorder of the tree:");
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    printf("Enter Inorder of the tree:");
    for(int i=0;i<n;i++)
        scanf("%d",&in[i]);
    printf("Postorder of the tree is:");
    postorder(in,pre,n);
    return 0;
}
