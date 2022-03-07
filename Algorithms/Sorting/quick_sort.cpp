// Time complexity -  Average case / Best Case: O(n logn), Worst Case - O(n^2)

#include <iostream>
using namespace std;

// utility function to swap elements
void swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}
/*Selecting the pivot element and then partitioning the array such that all the elements
left of pivot are less than it and all the elements greater
than it are on the right */
int partition(int arr[], int start, int end)
{
// initializing partition index with 0
    int pIndex = start;
// selecting last element as pivot
    int pivot = arr[end];

    for(int i=start; i<end; i++)
    {
// if we found any element < pivot, s
        if(arr[i] <= pivot)
        {
            swap(arr[i],arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[end]);
    return pIndex;
}
void quickSort(int arr[], int start, int end)
{
    // check for array bound, so that we don't go
// out of bound of array
    if(start < end)
    {
// getting partition index
        int pIndex = partition(arr,start,end);
// calling quicksort recursively for left sub array
        quickSort(arr,start,pIndex-1);
// calling quicksort recursively for right sub array
        quickSort(arr,pIndex+1,end);
    }
}

// util function to print array 
void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main() {
    
    int arr[] = {7,2,1,6,8,5,3,4};

    int n = sizeof(arr)/sizeof(arr[0]);
    int start = 0, end = n-1;
    quickSort(arr,start,end);
    printArray(arr,n);

}
