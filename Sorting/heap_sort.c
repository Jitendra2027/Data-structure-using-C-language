//Heap sort is a comparison based sorting technique based on Binary Heap data structure.
//It is similar to selection sort where we first find the maximum element and place the
//maximum element at the end. We repeat the same process for the remaining elements.
//Heap sort algorithm is divided into two basic parts:
//1.Creating a Heap of the unsorted list/array.(by calling maxHeap function)
//2.Then a sorted array is created by repeatedly removing the largest/smallest element
//from the heap, and inserting it into the array. The heap is reconstructed after each removal.
#include<stdio.h>
void heapSort(int *,int);
void maxHeap(int *,int ,int);
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

    heapSort(a,num);

    printf("\nArray elements after sorting:");
    for(i=0;i<num;i++)
        printf("%d ",a[i]);
    return 0;
}
//this function is used to create a binary heap tree
void maxHeap(int array[],int n,int x)
{
    int largest=x,temp;
    int l=2*x+1;//left child
    int r=2*x+2;//right child
    if(l<n && array[l]>array[largest])
        largest=l;
    if(r<n && array[r]>array[largest])
        largest=r;
    if(largest!=x)
    {
        //swapping if child is greater number
        temp=array[largest];
        array[largest]=array[x];
        array[x]=temp;

        //recursive call for child to child
        maxHeap(array,n,largest);
    }
}
void heapSort(int a[],int size)
{
    int i,temp;
    //creating max heap
    for(i=(size/2-1);i>=0;i--)
    {
        maxHeap(a,size,i);
    }
    //deleting elements from heap
    for(i=size-1;i>0;i--)
    {
        //root element which is largest value in the heap is put at the last of the array
        //at it's right position
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;

        //now again make the heap as binary tree
        maxHeap(a,i,0);
    }
}

//Complexity Analysis of Heap Sort
//1.Worst Case Time Complexity: O(n*log n)

//2.Best Case Time Complexity: O(n*log n)

//3.Average Time Complexity: O(n*log n)

//4.Space Complexity : O(1)

//Heap sort is not a Stable sort, and requires a constant space for sorting a list.
//Heap Sort is very fast and is widely used for sorting.
