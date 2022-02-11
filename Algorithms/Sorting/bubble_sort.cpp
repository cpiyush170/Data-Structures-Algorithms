/* In bubble sort, each pair of adjacent elements are compared and the elements are swapped if they are not follow the ordering rule. 
Time Complexity - O(n^2) - in worst case */

#include <iostream>
using namespace std;

// utility function to swap 
void swap(int arr[], int nextIndex, int currIndex){
    int temp = arr[nextIndex];
    arr[nextIndex] = arr[currIndex];
    arr[currIndex] = temp;
}

void bubble_sort(int arr[], int n){

    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j+1] < arr[j]){ // if next element is less than current element swap them
                swapped = true;
                swap(arr,j+1,j); 
            }
        }
        if(!swapped) break; // if not swapped break outer loop and array is sorted
    }
    
    // printing swapped array
    for(int i=0; i<=n-1; i++){
        cout << arr[i]<<" ";
    }
}
int main() {
    
    int arr[] = {4,3,7,1,5};
    
    int n = sizeof(arr)/sizeof(arr[0]); // calculating size of array
    bubble_sort(arr,n);
}
