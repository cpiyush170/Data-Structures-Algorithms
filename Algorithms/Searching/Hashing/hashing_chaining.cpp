#include <iostream>
#include <list>
using namespace std;

/*Implementation of hashing with chaining */ 

class Hash{

    int BUCKET; // no of buckets
    //pointer to an array containing buckets
    list<int> *table;
public:
    Hash(int V); // constructor

    //inserts a key into hash table
    void insertItem(int x);

    // deletes a key from hash table
    void deleteItem(int x);
    
    // hash function to map values to key
    int hashFunction(int x){
        return (x % BUCKET);
    }

    void displayHash();
};


Hash :: Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash :: insertItem(int key)
{
    // get the hash index of key
    int index = hashFunction(key);
    
    // put the key at the index given by hash function
    table[index].push_back(key);
}

void Hash :: deleteItem(int key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (index)th list
    list<int> :: iterator i;

    for(i = table[index].begin(); i != table[index].end(); i++){
        if(*i == key){
            break;
        }
    }
// if key is found in the hash table, remove it
    if(i != table[index].end()){
        table[index].erase(i);
    }
}
void Hash :: displayHash()
{
    for(int i = 0; i < BUCKET; i++){
        cout << i;
        for(auto x : table[i]){
            cout <<" --> "<< x;
        }
        cout << "\n";
    }
}

int main() {
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);

    Hash h(7);

    for(int i = 0; i < n; i++){
        h.insertItem(a[i]);
    }
    h.displayHash();
    h.deleteItem(12);

    cout <<"\n";
    h.displayHash();
}
