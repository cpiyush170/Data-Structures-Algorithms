#include <iostream>
using namespace std;

// Max - Heap creation using array

void InsertHeap(int* arr, int n){
    int temp = arr[n]; // keep last element in temp var
    int i = n;

    // keep looping until new element > parent and i > 1
    while(temp > arr[i/2] && i > 1){
        // if parent is < new element, put parent in current i
         if(arr[i/2] < temp){
             arr[i] = arr[i/2];
         }
         i = i/2;
    }
    // put temp at parent pos
    arr[i] = temp;
}
void createHeap(int arr[], int n){
    
// heap start from index 1
    int i = 2;
    while(i < n){
        InsertHeap(arr, i);
        i++;
    }
}
int main() {
    int arr[] = {0, 10, 20, 30, 25, 5, 40, 35};
    // size of array
    int n = sizeof(arr)/sizeof(arr[0]);
    // creating max- heap

    createHeap(arr, n);
    // displaying  max - heap
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
