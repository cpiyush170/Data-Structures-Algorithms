#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};

// insert node at end
Node* Insert(Node *head, int data){
    // creating a new node
    Node *newNode = new Node;

    // intializing node
    newNode->data = data;
    newNode->next = NULL;

    // if list is empty - make newNode as head node
    if(head == NULL)
    {
        head = newNode;
    }
    // else find last node and insert newNode there
    else{
        Node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node* reverseList(Node *head){

    Node *current, *prevNode, *nextNode;
    current = head;
    prevNode = NULL; // make prev node null
    
    while(current != NULL)
    {   
        // firstly, store the address of nextNode
        nextNode = current->next;
        
        // whatever is previous, set it as link part of current node
        current->next = prevNode;
        
        //update the previous as current
        prevNode = current;
        
        // make current point to next Node
        current = nextNode;
    }
    // adjust head with current previous node
    head = prevNode;
    return head;

}
// print list 
void printList(Node* head){

    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << " \n ";
}
int main() {
    struct Node* head = NULL; 
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,5);
    printList(head);
    head = reverseList(head);
    printList(head);
    

}
