//Binary Binary Search is a search algorithm that is used to find the position
// of an element (target value ) in a sorted array. The array should be sorted prior to applying a binary search.

//Binary search is also known by these names, logarithmic search, binary chop,
// half interval search.

#include<stdio.h>
int main()
{
    int n,num,i;
    printf("Enter the number of elements of the array:");
    scanf("%d",&n);
    int array[n];
    printf("Enter array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&num);
    int found=binary_search(array,0,n-1,num);
    if(found==-1)
         printf("Element not found in the array!");
    else
         printf("Element found in the array at %d position",(found+1));
    return 0;
}

int binary_search(int array[],int l,int r,int num)
{
    int mid=(l+r)/2;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(array[mid]==num)
            return mid;
        else if(array[mid]<num)
        {
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return -1;
}

//time complexity =o(logN base 2)
