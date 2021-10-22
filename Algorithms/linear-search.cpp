#include <iostream>
#define SIZE 5
using namespace std;

// defining a method to search an element in array

int LinearSearch(int arr[], int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key)
        return 1;
    }
    // it means key is not present in the array
    return 0;
}

int main() {
    int arr[SIZE] = {86,91,34,50,0};
    // key to search in array
    int key = 50;
    // if function returns 1 we've found element 
    // else not
    if(LinearSearch(arr,SIZE,key) == 1)
    cout << "Search Found" << endl;
    else
    cout << "Search Not Found" << endl;

    return 0;
}
