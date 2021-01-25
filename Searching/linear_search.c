#include<stdio.h>
int main()
{
    int n,num,flag=0,p,i;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int array[n];
    printf("Enter the array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    printf("Enter the element to be searched:");
    scanf("%d",&num);
    for(i=0;i<n;i++)
    {
        if(array[i]==num)
        {
            flag=1;
            p=i;
            break;
        }
        else
            flag=0;
    }
    if(flag)
        printf("Number found at %d",(p+1));
    else
        printf("Number not found!");
    return 0;
}
