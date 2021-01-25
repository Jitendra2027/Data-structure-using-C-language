//Merge Sort follows the rule of Divide and Conquer to sort a given set of numbers/elements,
// recursively, hence consuming less time.Merge sort , on the other hand, runs in O(n*log n)
//time in all the cases.
#include<stdio.h>
void mergeSort(int *,int,int);
void merge(int *,int,int,int);
int main()
{
    int num,i;
    printf("Enter the number of elements:");
    scanf("%d",&num);
    int a[num];
    printf("Enter array elements:");
    for(i=0;i<num;i++)
        scanf("%d",&a[i]);
    printf("\nArray elements before sorting:");
    for(i=0;i<num;i++)
        printf("%d ",a[i]);

    mergeSort(a,0,num-1);

    printf("\nArray elements after sorting:");
    for(i=0;i<num;i++)
        printf("%d ",a[i]);
    return 0;
}
void mergeSort(int array[],int start, int end)
{
    int mid;
    if(start<end)
    {
        mid=(start+end)/2;
        mergeSort(array,start,mid);
        mergeSort(array,mid+1,end);

        merge(array,start,mid,end);
    }
}
void merge(int array[],int start,int mid,int end)
{
    int i,j,k,b[end+1];
    i=start;
    j=mid+1;
    k=start;
    while(i<=mid && j<=end)
    {
        if(array[i]<=array[j])
        {
            b[k]=array[i];
            i++;
        }
        else
        {
            b[k]=array[j];
            j++;
        }
        k++;
    }
        if(i>mid)
        {
            while(j<=end)
            {
               b[k]=array[j];
               k++;
               j++;
            }
        }
        else
        {
            while(i<=mid)
            {
               b[k]=array[i];
               k++;
               i++;
            }
        }

    for(k=start;k<=end;k++)
        array[k]=b[k];
}
//Merge Sort is quite fast, and has a time complexity of O(n*log n). It is also a stable
// sort, which means the "equal" elements are ordered in the same order in the sorted list.
//Worst Case Time Complexity [ Big-O ]: O(n*log n)

//Best Case Time Complexity [Big-omega]: O(n*log n)

//Average Time Complexity [Big-theta]: O(n*log n)

//Space Complexity: O(n)
