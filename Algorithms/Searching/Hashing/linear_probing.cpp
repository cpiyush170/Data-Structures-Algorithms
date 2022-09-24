#include <iostream>
#define SIZE 10
using namespace std;

// Closed Hashing:
// Open addressing : linear probing

/*Like separate chaining, open addressing is a method 
for handling collisions. In Open Addressing, all 
elements are stored in the hash table itself. 
So at any point, the size of the table must be greater 
than or equal to the total number of keys 
(Note that we can increase table size by copying old 
data if needed). This approach is also known as 
closed hashing. This entire procedure is based upon 
probing.*/
int hashFunc(int key)
{
    return (key % SIZE);
}

int probe(int H[], int key)
{
    int index = hashFunc(key);

    int i = 0;
    while(H[(index + i)%SIZE] != 0)
        i++;
    return (index + i) % SIZE;
}
void Insert(int H[], int key)
{
    int index = hashFunc(key);

    if(H[index] != 0){
        index = probe(H, key);
    }
    H[index] = key;
   
}
int Search(int H[], int key)
{
    int index = hashFunc(key);
    int i = 0;
    while(H[(index + i)%SIZE] != key)
        i++;
// returning index of key
    return (index + i)%SIZE;
}

void displayHT(int H[])
{
    for(int i = 0; i < SIZE; i++){
        cout << i << "  --> "<< H[i] << endl;
    }
}
int main() {
// declaring hash table
   int HT[SIZE] = {0};

   Insert(HT, 12);
   Insert(HT, 50);
   Insert(HT, 39);
   Insert(HT, 22);
   
   displayHT(HT);

   cout <<Search(HT, 39);
}
