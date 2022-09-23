#include <iostream>
using namespace std;

// Collision Avoidation Method: 
// Open Chaining: Closed Addressing

struct Node{
    int data;
    Node *next;

// constructor for node
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void sortedInsert(Node **head, int x)
{
    Node *newNode = new Node(x);
// temporary node for traversing list
    Node *temp = *head, *q = NULL;
// if list is empty, make newNode as head

    if(*head == NULL) *head = newNode;
    else
    {
// keep traversing until temp->data < x
        while(temp && temp->data < x)
        {
            q = temp;
            temp = temp->next;
        }
// insert at head, if temp->data > x
        if(temp == *head)
        {
            newNode->next = *head;
            *head = newNode;
        }
        else
        {
            q->next = newNode;
        }
    }
}

Node* search(Node *p, int key)
{
    while(p != NULL)
    {
        if(p->data == key) return p;
        p = p->next;
    }
    return NULL;
}

// hash function 
int hashFunc(int key)
{
    return key % 10;
}
void InsertHT(Node *H[], int key)
{
    // get hash index
    int index = hashFunc(key);
    // inserting in hash table
    sortedInsert(&H[index], key);
}

void displayHT(Node *HT[])
{
    for(int i = 0; i < 10; i++){
        cout << i;
        Node *p = HT[i];
        while(p != NULL){
            cout << " --> " << p->data;
            p = p->next;
        }
        cout << endl;
    }
}
int main() {
    // hash table with array of pointers of type Node
    Node *HT[10];

    // assigning NULL
    for(int i = 0; i < 10; i++){
        HT[i] = NULL;
    }
// Inserting in hash table
    InsertHT(HT, 12);
    InsertHT(HT, 22);
    InsertHT(HT, 42);
    InsertHT(HT, 10);
    InsertHT(HT, 5);
    InsertHT(HT, 9);
    displayHT(HT);
}
