//insertion in array means we are going to insert a item in the array at a specific position
//we can directly perform the insertion without first taking the array elements as we done
//in our program written follow.
#include<stdio.h>
void display(int,int *);
int main()
{
    int a[20],i,size;
    int pos,num;
    printf("Enter the size of the array(<20):");
    scanf("%d",&size);
    printf("Enter the array elements:");
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
    display(size,a);
    printf("\nNow we perform the insertion operation in the array:-\n");
    do
    {
        if(size<20)
        {
            printf("Enter the position:");
            scanf("%d",&pos);
            printf("Enter the data to be inserted:");
            scanf("%d",&num);
            if(pos<0 || pos>size+1)
                printf("Item can not inserted...!\n");
            else
            {
                for(i=size-1;i>=pos-1;i--)
                    a[i+1]=a[i];
                a[pos-1]=num;
                size++;
                printf("Item %d inserted successfully at position %d...!\n",num,pos);
            }
            printf("Enter 1 to continue and 0 to exit:-");
            scanf("%d",&i);
        }
        else
            printf("Array is full...!\n");
    }
    while(i!=0);
    display(size,a);
    return 0;
}
void display(int size,int a[])
{
    printf("Your array is:");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
}
//for a unsorted array we can directly insert the element at the position by swapping it with
//the last element of the array because we only want to insert the element,and it saves the
//time.Time complexity for this is o(1),and time complexity for the above program is o(n-p).

//but for the sorted array we have to insert the item at the position and shift the following
//items.
