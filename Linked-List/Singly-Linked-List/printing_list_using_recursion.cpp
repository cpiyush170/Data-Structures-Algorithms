#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *addFront(Node *head, int val){
    Node *newNode = new Node();
    newNode->data = val;

        newNode->next = head;
        head = newNode;
    return head;
}
// printing list using recursion in reverse order

void printListReverse(Node *head){

    Node *temp = head;
    if(temp == NULL) 
    {
        return;
    }
    
    printListReverse(temp->next);
    cout << temp->data<<" ";
   
}
    
void printListForward(Node *head){
    Node *temp = head;
    if(temp == NULL) 
    {
        return;
    }
    
    cout << temp->data<<" ";
    printListForward(temp->next);
}
int main() {
    Node *head = NULL;
    head = addFront(head,48);
    head = addFront(head,20);
    head = addFront(head,12);
    // calling print function to print list using 
    // recursion in forward order
    printListForward(head);
    cout <<"\n";
    // calling print function to print list using 
    // recursion in reverse order
    printListReverse(head);
}
