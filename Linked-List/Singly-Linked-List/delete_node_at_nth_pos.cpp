#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node *head;
// insert node at end
void Insert(int data){
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
}
void deleteNode(int n){

    Node *temp1 = head;
    // if you want to delete head node
    if( n == 1)
    {   
        head = temp1->next;
        delete(temp1);
        return;
    }
    // loop till node to be deleted - 1
    for(int i=1; i<n-1; i++)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete (temp2);
}
// print list 
void prinList(){
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << " \n ";
}
int main() {
    head = NULL; // list is empty
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    prinList();
    deleteNode(4);
    prinList();

}
