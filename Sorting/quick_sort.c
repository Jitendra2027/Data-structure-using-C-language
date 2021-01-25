//Quicksort is a divide and conquer algorithm. The steps are:
//1) Pick an element from the array, this element is called as pivot element.
//2) Divide the unsorted array of elements in two arrays with values less than the pivot
// come in the first sub array, while all elements with values greater than the pivot come
//in the second sub-array (equal values can go either way). This step is called the
//partition operation. 3) Recursively repeat the step 2(until the sub-arrays are sorted)
//to the sub-array of elements with smaller values and separately to the sub-array of
//elements with greater values.It is also called partition-exchange sort.

#include"stdio.h"
void quickSort(int *,int ,int);
void swap(int *,int *);
int main()
{
    int num,i;
    printf("Enter the number of array elements:");
    scanf("%d",&num);
    int a[num];
    printf("Enter the array elements:");
    for(i=0;i<num;i++)
        scanf("%d",&a[i]);

    printf("\nArray elements before sorting:");
    for(i=0;i<num;i++)
        printf("%d ",a[i]);

    quickSort(a,0,num-1);

    printf("\nArray elements after sorting:");
    for(i=0;i<num;i++)
        printf("%d ",a[i]);
    return 0;
}

//when first element is taken as pivot.

/*void quickSort(int array[],int start,int end)
{
    int i,j,pivot;
    if(start<end)
    {
         pivot=start;
         i=start;
         j=end;

         while(i<j)
         {
            while(array[pivot]>=array[i] && i<end)
                  i++;
            while(array[pivot]<array[j])
                  j--;
            if(i<j)
                  swap(&array[i],&array[j]);
         }
         swap(&array[pivot],&array[j]);

         quickSort(array,start,j-1);
         quickSort(array,j+1,end);
    }
}
*/

//when last element is taken as pivot
void quickSort(int array[],int start,int end)
{
    int i,j,pivot;
    if(start<end)
    {
         pivot=end;
         i=start;
         j=end;

         while(i<j)
         {
            while(array[pivot]<=array[j]&& j>start)
                  j--;
            while(array[pivot]>array[i])
                  i++;
            if(i<j)
                  swap(&array[i],&array[j]);
         }
         swap(&array[pivot],&array[i]);

         quickSort(array,start,i-1);
         quickSort(array,i+1,end);
    }
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

//Worst Case Time Complexity [ Big-O ]: O(n2)

//Best Case Time Complexity [Big-omega]: O(n*log n)

//Average Time Complexity [Big-theta]: O(n*log n)

//Space Complexity: O(n*log n)
