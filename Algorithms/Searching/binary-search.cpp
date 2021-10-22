//Implementation of binary search (iterative method)

#include <iostream>
#define SIZE 5
using namespace std;

int BinarySearch(int arr[], int size, int x){
    // start and end to keep track of array
    int start = 0, end = size-1;
    
    while(start <= end){
        int mid = (start+end)/2;
// case1: if middle element == element to searched for
        if(arr[mid] == x){
            return mid;
        }
       
// case2: if element to searched for < middle element
// adjust end by subtracting 1 from mid
        else if(x < arr[mid]){
        end = mid - 1;
        }
        else{
        start = mid + 1;
        }
    }
    return -1;
}
int main() {
    int arr[SIZE] = {12,30,49,70,80};
    // element to be found
    int x = 30;
    int index = BinarySearch(arr, SIZE, x);
    if(index != -1)
cout <<"Number "<< x << " is at index: " << index <<endl;
    else
    cout <<"Number " << x << " is not found" <<endl;
    

}
