//Counting sort is a sorting algorithm that sorts the elements of an array by counting the
//number of occurrences of each unique element in the array. The count is stored in an
//auxiliary array and the sorting is done by mapping the count as an index of the auxiliary
//array.count sort is not based on comparision sort as other sorting algorithm.

#include<stdio.h>
void countSort(int *,int);
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

    countSort(a,num);

    printf("\nArray elements after sorting:");
    for(i=0;i<num;i++)
        printf("%d ",a[i]);
    return 0;
}
void countSort(int array[],int n)
{
    int max;
    int b[n];
    max=array[0];
    for(int i=0;i<n;i++)
    {
        if(array[i]>max)
            max=array[i];
    }
    int count[10]={0};
    for(int i=0;i<n;i++)
        count[array[i]]++;
    for(int i=1;i<=max;i++)
        count[i]=count[i]+count[i-1];
    for(int i=n-1;i>=0;i--)
    {
        b[count[array[i]]-1]=array[i];
        count[array[i]]--;
    }
    for(int i=0;i<n;i++)
        array[i]=b[i];
}

//Complexity
//Time Complexities:
//  There are mainly four main loops. (Finding the greatest value can be done outside
//  the function.)

//for-loop	time of counting
// 1st	O(max)
// 2nd	O(size)
// 3rd	O(max)
// 4th	O(size)
//Overall complexity = O(max)+O(size)+O(max)+O(size) = O(max+size)

//Worst Case Complexity: O(n+k)
//Best Case Complexity: O(n+k)
//Average Case Complexity: O(n+k)

//The space complexity of Counting Sort is O(max). Larger the range of elements, larger
// is the space complexity.
