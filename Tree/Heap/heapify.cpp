#include <iostream>
using namespace std;

int size = 0;

// util function to swap elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// function that make sure that list follow heap property (we used max-heap here)
void heapify(int arr[], int size, int i)
{
    if(size == 1)
    {
    cout<<"Single element in the heap";
    }
    else
    {
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        if(l < size && arr[l] > arr[largest])
        largest = l;
        if(r < size && arr[r] > arr[largest])
        largest = r;

        if(largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(arr,size,largest);
        }
    }
}
// util function to insert element in heap
void insert(int arr[], int newNum)
{
// when size == 0 put element in first index & increase size
    if(size == 0)
    {
        arr[0] = newNum;
        size += 1;
    }
// else put element in next empty position
    else
    {
        arr[size] = newNum;
        size += 1;
// creating heap using heapify
    for(int i=size/2-1; i>=0; i--)
    {
        heapify(arr,size,i);
    }

    }
}
// function to delete an element from heap
void deleteRoot(int arr[], int num)
{
    int i;
    for( i=0; i<size; i++)
    {
        if(num == arr[i]) break;
    }

    swap(&arr[i], &arr[size-1]);
    size -= 1;
    
    for(int i = size/2 - 1; i>=0; i--)
    {
        heapify(arr,size,i);
    }
}

void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main() {

    int arr[10];

    insert(arr,3);
    insert(arr,4);
    insert(arr,9);
    insert(arr,5);
    insert(arr,2);

    cout<<"Max-Heap array: ";
    printArray(arr,size);
    
    deleteRoot(arr,4);
    cout<<"After deleting an element: ";
    printArray(arr,size);
}
