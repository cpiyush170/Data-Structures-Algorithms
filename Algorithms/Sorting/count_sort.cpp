#include <iostream>
using namespace std;
// Count Sort is linear time sorting algorithm
// It's time complexity is O(n) and it takes extra 
// space to do sorting in linear time

int findMax(int arr[], int n)
{
    int max = arr[0];
   for(int i = 1; i < n; i++){
       if(arr[i] > max){
           max = arr[i];
       }
   }
   return max;
}
void countSort(int arr[], int n)
{
    int max = findMax(arr, n);

    int temp[max + 1] = {0};

// count every element in array
    for(int i = 0; i < n; i++){
        temp[arr[i]]++;
    }

// put back elements in original array to make to
// sorted from count array
    int i = 0, j = 0;

    while(i < max + 1)
    {
        if(temp[i] > 0){
            arr[j++] = i;
            temp[i]--;
        }
        else{
            i++;
        }
    }
}
void display(int arr[], int n)
{
    for(int i = 0; i < n; i++){
        cout << arr[i] <<" ";
    }
}
int main() {
    
    int arr[] = {7, 2, 9, 3, 2, 4, 6, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    countSort(arr, n);
    display(arr, n);
}
