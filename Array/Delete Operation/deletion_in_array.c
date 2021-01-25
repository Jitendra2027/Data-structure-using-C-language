#include<stdio.h>
void display(int,int *);
int main()
{
    int a[20],i,size;
    int pos,item;
    printf("Enter the size of the array(<20):");
    scanf("%d",&size);
    printf("Enter the array elements:");
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
    display(size,a);
    printf("\nNow we perform the deletion operation in the array:-\n");
    do
    {
        if(size<20 && size>0)
        {
            printf("Enter the position:");
            scanf("%d",&pos);
            item=a[pos-1];
            if(pos<0 || pos>size+1)
                printf("Item can not deleted...!\n");
            else
            {
                for(i=pos-1;i<size;i++)
                    a[i]=a[i+1];
                size--;
                printf("Item %d deleted successfully from position %d...!\n",item,pos);
            }
        }
        else
            printf("Array is empty...!\n");
        printf("Enter 1 to continue and 0 to exit:-");
        scanf("%d",&i);
    }
    while(i!=0);
    display(size,a);
    return 0;
}
void display(int size,int a[])
{
    if(size==0)
        printf("Your array is empty...!\n");
    else
    {
        printf("Your array is:");
        for(int i=0;i<size;i++)
            printf("%d ",a[i]);
    }
}
//As same as insertion operation in deletion operation we can delete the item from given
//position and put the last item of the array at the same position.
//a[pos-1]=a[size-1]; and print the array till size-2
