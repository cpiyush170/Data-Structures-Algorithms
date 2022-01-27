#include <iostream>
using namespace std;

// representation of node
struct Node{
    int data;
    Node *next;
};
//declaring head node as global
Node *head = NULL;
// function to add node in list
Node* addLast(Node *head, int val){
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL)// head point to nowhere
    {
        head = newNode;
    }
    else
    {
        Node *last = head;
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
    }
    return head;
}
Node* reverse(Node *head){

    // base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    // returning newHead (last node) (recursive case)
    Node *newHead = reverse(head->next);
    // storing current head's next ref in headNext
    Node *headNext = head->next;
    // making headNext's next current head(reverse link)
    headNext->next = head;
    head->next = NULL;
    // last node
    return newHead;
}
void printList(Node *head){
    Node *temp = head;

    while(temp != NULL)
    {   
        cout << temp->data <<" ";
        temp = temp->next;
    }

}
int main() {
    // passing address of head & returning modified head
     head = addLast(head,10);
     head = addLast(head,5);
     head = addLast(head,7);
     head = addLast(head,4);
     printList(head);
     head = reverse(head);
     cout <<"\n";
     printList(head);
}
