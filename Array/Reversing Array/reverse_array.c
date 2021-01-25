#include<stdio.h>
void reverse(int *,int);
void display(int *,int);
int main()
{
    int a[20],i,size;
    printf("Enter the size of the array(<20):");
    scanf("%d",&size);
    printf("Enter the array elements:");
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
    printf("Your array is before reversing:");
    display(a,size);
    printf("\nArray after reversing is:");
    reverse(a,size);
    display(a,size);
    return 0;
}
void reverse(int a[],int size)
{
    int start=0,end=size-1,temp;
    while(start<end)
    {
        temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
}
void display(int a[],int size)
{
     for(int i=0;i<size;i++)
        printf("%d ",a[i]);
}
