#include <iostream>
using namespace std;

// It is a variation of insertion Sort

void shellSort(int a[], int n)
{
    int gap, i, j, temp;

    for(gap = n/2; gap >= 1; gap /= 2)
    {
        for(i = gap; i < n; i++){
            temp = a[i];
            j = i - gap;
            while(j >= 0 && a[j] > temp)
            {
                a[j + gap] = a[j];
                j = j - gap;
            }
            a[j + gap] = temp;
        }
    }
}

void display(int a[], int n)
{
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
int main() {
    int a[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = 10;
    shellSort(a, n);
    display(a, n);
}
