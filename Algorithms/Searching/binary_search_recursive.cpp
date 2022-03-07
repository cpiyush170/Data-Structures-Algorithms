#include <iostream>
using namespace std;

int binarySearch(int arr[],int low, int high, int key)
{
    // when our search space is exhausted
    if(low > high) return -1;

// calculating median
    int mid = low+(high-low)/2;

// if element lie at mid index 
    if( key == arr[mid]) return mid;

// if element key(element to be found) < element at mid
    else if(key < arr[mid])
    return binarySearch(arr,low,mid-1,key);

    else
    return binarySearch(arr,mid+1,high,key);


}
int main() {
    
    int arr[] = {1,4,9,21,32,84};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0, high = n-1;
    cout<< "Element was found "
    << "at index " <<binarySearch(arr,low,high,9);
}
