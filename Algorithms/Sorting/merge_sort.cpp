/* Merge Sort Algorithm

At every step n operations are performed and
each step we are dividing array into half so,
logn steps are performed with n operations at each
step.
So, time complexity will be O(nlogn) 
It is stable algorithm, i.e - it preserve the relative order of the original array, but it's not in-place algorithm*/

#include <iostream>
using namespace std;

// temporary array for storing each sorted element
int arr_B[7];

// method to merge  sorted sub_arrays
void MergeArray(int arr_A[],int l,int mid,int r){
    int i = l; // left index (0) assigned to i;
    int j = mid+1; // start index of sub_array
    int k = l; // assign l (0) to k for new array

// while we are inside left sub_array and right sub_array
    while(i <= mid && j <= r)
    {
// if element of left sub_array is < right sub_array
// put smaller element in new array
        if(arr_A[i] < arr_A[j])
        {
            arr_B[k] = arr_A[i];
            i++;
        }
// else put smaller element of right sub_array 
// into new array
        else{
            arr_B[k] = arr_A[j];
            j++;
        }
        k++;
    }
// if our indexes goes out of bound for sub_arrays
// then put left over element in new array

// if our left sub_array is exhausted then put all the 
// remaining elements of right sub_array into new array
    if(i > mid)
    {
        while(j <= r)
        {
            arr_B[k] = arr_A[j];
            j++; k++;
        }
    }
// when our right sub_array is exhausted, put all
// our left sub_array elements into new array
    else{
        while(i<=mid)
        {
            arr_B[k] = arr_A[i];
            i++; k++;
        }
    }
    for(int k=l; k<=r; k++){
        arr_A[k] = arr_B[k];
    }
}
void MergeSort(int arr_A[], int l, int r){
    // divide the array in half, if only possible
    if(l < r){

    int mid = (l+r)/2;
    MergeSort(arr_A,l,mid);
    MergeSort(arr_A,mid+1,r);
    MergeArray(arr_A,l,mid,r);
    }
}
int main() {

    int arr_A[] = {9,4,7,6,3,1,5};
    int n = sizeof(arr_A)/sizeof(arr_A[0]);
    MergeSort(arr_A,0,n-1);

  // printing array after merge sort
    for(int i=0; i<n; i++)
    {
        cout << arr_A[i]<<" ";
    }
}
