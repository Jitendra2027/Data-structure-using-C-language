//traversing means to visit each and every element of the array.
//we are printing the array it means we have visited the every element of the array.
#include<stdio.h>
int main()
{
    int a[20],i,size;
    printf("Enter the size of the array(<20):");
    scanf("%d",&size);
    printf("Enter the array elements:");
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
    printf("Your array is:");
    for(i=0;i<size;i++)
        printf("%d ",a[i]);
    return 0;
}
