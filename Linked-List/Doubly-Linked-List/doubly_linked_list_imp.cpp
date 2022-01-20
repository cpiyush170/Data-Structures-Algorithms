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
    printDLL(head);
}
