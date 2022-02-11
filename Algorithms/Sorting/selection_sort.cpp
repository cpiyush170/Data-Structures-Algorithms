/* In selection sort, we will select the optimal element for every index by comparing all other elements.*/

#include <iostream>
using namespace std;

int* selection_sort(int* arr, int n){

    
    for(int i=0; i<n-1; i++){

        int iMin = i;
        for(int j=i+1; j<n; j++){

            if(arr[j] < arr[iMin])
                iMin = j;
        }
        int temp = arr[i];
        arr[i] = arr[iMin];
        arr[iMin] = temp;
    }
    return arr;
}
int main() {
    
    int arr[] = {2,7,4,1,5,3};

    int n = sizeof(arr)/sizeof(arr[0]);
    int* Arr = selection_sort(arr,n);

    for(int i=0; i<n; i++){
        cout << Arr[i] <<" ";
    }
}
