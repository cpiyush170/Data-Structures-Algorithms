#include <iostream>
#define size 5
using namespace std;

class Queue{

public:
    int arr[size];
    int front;
    int rear;
    Queue(){
        front = -1;
        rear = -1;
    }
// Enqueue operation is used to add item in queue
    void Enqueue(int);
    void Dequeue();
    bool isFull();
    bool isEmpty();
    void printQueue(){
        for(int i=front; i<=rear; i++)
        {   
            if(front >= 0)
            cout << arr[i] <<" ";
        }
    }
};

bool Queue :: isFull()
{
    if(rear == size - 1)
    return true;
    
    return false;
}
bool Queue :: isEmpty(){
    if( rear == -1 && front == -1)
    return true;

    return false;
}
void Queue :: Enqueue(int x)
{
    if(isFull())
    return;

    else if(isEmpty())
    {
       front++;
       rear++;
       arr[rear] = x;
    }
    else{
        arr[++rear] = x;
    }
}
void Queue :: Dequeue()
{
    if(isEmpty())
    {
    cout << "Queue is empty" << endl;
    }
    // if queue has only 1 element
    else if(front == rear)
    {
        // we will set front & rear -1 to
        // represent empty queue
        front = -1, rear = -1;
    }
    else
    front++;
    
}
int main() {
    Queue q1;
    q1.Enqueue(2);
    q1.Enqueue(5);
    q1.Enqueue(7);
    q1.Enqueue(6);
    q1.Enqueue(8);
    q1.printQueue();
    cout << "\n";
    q1.Dequeue();
    q1.Dequeue();
    q1.Dequeue();
    q1.Dequeue();
    q1.Dequeue();
    q1.Dequeue();
    q1.printQueue();
}
