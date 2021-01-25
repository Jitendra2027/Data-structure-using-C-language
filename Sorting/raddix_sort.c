//The idea of Radix Sort is to do digit by digit sort starting from least significant digit
// to most significant digit. Radix sort uses counting sort as a subroutine to sort.
//The Radix sort is a non-comparative sorting algorithm.
#include<stdio.h>
void raddixSort(int *,int);
int getMax(int *,int);
void countSort(int *,int,int);
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

    raddixSort(a,num);

    printf("\nArray elements after sorting:");
    for(i=0;i<num;i++)
        printf("%d ",a[i]);
    return 0;
}
void raddixSort(int array[],int size)
{
    int max=getMax(array,size);

    for(int j=1;max/j>0;j*=10)
        countSort(array,size,j);
}
int getMax(int array[],int size)
{
    int max=array[0];
    for(int i=1;i<size;i++)
    {
        if(array[i]>max)
            max=array[i];
    }
    return max;
}
void countSort(int array[],int size,int pos)
{
    int count[10]={0};
    int b[size];
    int j;
    for(j=size-1;j>=0;j--)
        count[array[j]/pos%10]++;
    for(j=1;j<10;j++)
        count[j]+=count[j-1];
    for(j=size-1;j>=0;j--)
    {
        b[count[array[j]/pos%10]-1]=array[j];
        count[array[j]/pos%10]--;
    }
    for(j=0;j<size;j++)
        array[j]=b[j];
}

//The complexity of Radix Sort Technique
// Time Complexity: O(n*k)=>because count sort is applied n(number of digits) times.
// Space Complexity: O(n+k)=>one extra array of size n(array b) and one of size k(count array).
