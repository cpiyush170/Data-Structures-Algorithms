#include <iostream>
using namespace std;

class Node{
    int data;
    Node *next;
 public:
    Node(){};
    void enqueue(int);
    void dequeue();
    bool IsEmpty();
    int frontElem();
    void printQueue();
    
};

Node *front = NULL;
Node *rear = NULL;
void Node :: enqueue(int x){

    // created a node
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    // is queue is empty
    if((front == NULL) && (rear == NULL))
    {
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode; // pointing rear to newNode
        rear = newNode;
    }
}
void Node :: dequeue(){
    Node *temp = front;
    if(front == NULL) return;

    else if(front == rear)
    {
        front = rear = NULL;
    }
    else{
        front = front->next;
        delete (temp);
    }
}
bool Node :: IsEmpty(){
    if(front == NULL && rear == NULL)
    return true;
    else
    return false;
}
int Node :: frontElem(){
    return front->data;
}
void Node :: printQueue(){
        Node *temp = front;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
}
int main() {
    Node q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(88);
    q.enqueue(49);
    q.dequeue();
    q.dequeue();
    cout << q.frontElem()<<endl;
    q.printQueue();

}
