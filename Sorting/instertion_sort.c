//Insertion sort is a simple sorting algorithm that works similar to the way you sort
// playing cards in your hands. The array is virtually split into a sorted and an unsorted
// part. Values from the unsorted part are picked and placed at the correct position in the sorted par

#include<stdio.h>
void insertionSort(int *, int);
int main()
{
    int n,i;
    printf("Enter the number of elements of the array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("\nArray elements before sorting:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    insertionSort(a,n);

    printf("\nArray elements after sorting:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}

void insertionSort(int array[], int size)
{
   int i,j;
   for(i=1;i<size;i++)
   {
       int key=array[i];
       j=i-1;
       while(j>=0 && array[j]>key)
       {
           array[j+1]=array[j];
           j=j-1;
       }
       array[j+1]=key;
   }
}

//Worst Case Time Complexity [ Big-O ]: O(n2)

//Best Case Time Complexity [Big-omega]: O(n)

//Average Time Complexity [Big-theta]: O(n2)

//Space Complexity: O(1)
