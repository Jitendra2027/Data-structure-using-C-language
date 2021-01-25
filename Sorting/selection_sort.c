//Selection sort is conceptually the most simplest sorting algorithm. This algorithm will first find the smallest element
//in the array and swap it with the element in the first position, then it will find the second smallest element
//and swap it with the element in the second position, and it will keep on doing this until the entire array is sorted.
//It is called selection sort because it repeatedly selects the next-smallest element and swaps it into the right place.
#include<stdio.h>
void selectionSort(int *,int );
int main()
{
    int num,i;
    printf("Enter the number of elements of the array:");
    scanf("%d",&num);
    int a[num];
    printf("Enter the array elements:");
    for(i=0;i<num;i++)
        scanf("%d",&a[i]);

    printf("\nArray elements before sorting:");
    for(i=0;i<num;i++)
        printf("%d ",a[i]);

    selectionSort(a,num);

    printf("\nArray elements after sorting:");
    for(i=0;i<num;i++)
        printf("%d ",a[i]);

    return 0;
}

void selectionSort(int array[],int size)
{
    int i,j,min;
    for(i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size;j++)
            if(array[j]<array[min])
                min=j;
        int temp=array[min];
        array[min]=array[i];
        array[i]=temp;
    }
}
/*
void selectionSort(int array[],int size)
{
    int i,j,min;
    for(i=0;i<size-1;i++)
    {
        min=array[i];
        for(j=i+1;j<size;j++)
            if(array[j]<min)
                min=array[j];
        int temp=min;
        min=array[i];
        array[i]=temp;

    }
}
*/

//Worst Case Time Complexity [ Big-O ]: O(n2)

//Best Case Time Complexity [Big-omega]: O(n2)

//Average Time Complexity [Big-theta]: O(n2)

//Space Complexity: O(1)


