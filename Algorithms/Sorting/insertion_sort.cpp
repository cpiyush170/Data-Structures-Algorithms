#include <iostream>
using namespace std;

// In insertion sort divide list into sorted and unstored
// section and then shift elements accordingly
int* insert_sort(int n){

// creating array in heap section of memory of size n
    int *p = (int*)malloc(n * sizeof(int));

// taking input from user into array
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
     cout << "Array before sorting: ";
    for(int i=0; i<n; i++){
        cout << p[i]<<" ";
    }
    cout << "\n";

    // insertion sort method
    // start from index 1 till n-1
    for(int i=1; i<n; i++)
    {
        int curr_val = p[i]; // store current index value of array
        int curr_index = i; // store current index of array
        
// if current_index > 0 and value of previous element is greater than current value then, swap them 
while( curr_index > 0 && p[curr_index-1] > curr_val)
{
    p[curr_index] = p[curr_index-1];
    curr_index--;
}
    p[curr_index] = curr_val;
    }
    return p;

}

int main() {

    int n;
    cout << "Enter size of array: "<<endl;
    cin>>n;
    cout << "\n";
    int *ptrArray = insert_sort(n);

    // printing sorted array
    cout << "Array after sorting: ";
    for(int i=0; i<n; i++){
        cout << ptrArray[i]<<" ";
    }
}
