#include <iostream>
using namespace std;

// Max - Heap creation using array

void InsertHeap(int* arr, int n){
    int temp = arr[n];
    int i = n;

    while(temp > arr[i/2] && i > 1){
         if(arr[i/2] < temp){
             arr[i] = arr[i/2];
         }
         i = i/2;
    }
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

void deleteFromHeap(int A[], int n){
    int x, i, j;
    x = A[n-1];
    A[1] = A[n-1];
    i = 1, j = 2 * i;

    while(j < n - 1)
    {
        if(A[j+1] > A[j]){
            j = j+1;
        }
        if(A[i] < A[j]){
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else break;
        
    }

}
int main() {
    int arr[] = {0, 10, 20, 30, 25, 5, 40, 35};
    // size of array
    int n = sizeof(arr)/sizeof(arr[0]);
    // creating max- heap

    createHeap(arr, n);
    deleteFromHeap(arr, n);
    // displaying  max - heap
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
