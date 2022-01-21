#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
};
Node* addFront(Node *head, int val){

    // creating a node
    Node *newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
    head->prev = newNode;
    head = newNode;
    return head;
}
void addAfterGivenNode(Node *prev_node, int val){

    if(prev_node == NULL)
    {
        cout<<"previous node can't be null";
    }
    // creating a node
    Node *newNode = new Node();
    newNode->data = val;
    // make prev part of new node point to previous node
    newNode->prev = prev_node;
    // make next part of new node point to next of previous node
    newNode->next = prev_node->next;
    // point previous node to new node
    prev_node->next = newNode;
    if(newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
    

}
void addAtEnd(Node *head, int val){
    // creating a node
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    
     /* If the Linked List is empty, then make the new
        node as head */
    if(head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}
void addBefore(Node *next_node, int val){
    // creating a node
    Node *newNode = new Node();
    newNode->data = val;
    
    if(next_node == NULL)
    {
        return;
    }
    newNode->next = next_node;
    newNode->prev = next_node->prev;
    next_node->prev->next = newNode;
    next_node->prev = newNode;
}
void printDLL(Node *head){

    if(head != NULL)
    {
        cout << head->data << " ";
        printDLL(head->next);
    }
}
int main() {
    Node *head = NULL;
    head = addFront(head,20);
    head = addFront(head,40);
    head = addFront(head,60);
    head = addFront(head,80);
    addAfterGivenNode(head->next,77);
    addAtEnd(head,50);
    addBefore(head->next->next,359);
    printDLL(head);
}
