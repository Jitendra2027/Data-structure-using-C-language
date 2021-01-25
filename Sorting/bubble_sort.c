//Bubble Sort is the simplest sorting algorithm that works by repeatedly
//swapping the adjacent elements if they are in wrong order.
//It is known as bubble sort, because with every complete iteration the largest
//element in the given array
#include<stdio.h>
void bubbleSort(int *,int);
int main()
{
    int n,i;
    printf("Enter the number of elements of the array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nArray before sorting:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    bubbleSort(a,n);

    printf("\nArray after sorting:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
 void bubbleSort(int a[],int size)
{
    int i,j,temp;
    for(i=0;i<(size-1);i++)
    {
        for(j=0;j<(size-i-1);j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

//In Bubble Sort, n-1 comparisons will be done in the 1st pass,
//n-2 in 2nd pass, n-3 in 3rd pass and so on. So the total number of comparisons will be,
//(n-1) + (n-2) + (n-3) + ..... + 3 + 2 + 1
//Sum = n(n-1)/2
//i.e O(n2) Hence the time complexity of Bubble Sort is O(n2).
//The space complexity for Bubble Sort is O(1), because only a single additional
//memory space is required i.e. for temp variable.
//Also, the best case time complexity will be O(n), it is when the list is already sorted

//Worst Case Time Complexity [ Big-O ]: O(n2)
//Best Case Time Complexity [Big-omega]: O(n)
//Average Time Complexity [Big-theta]: O(n2)
//Space Complexity: O(1)
