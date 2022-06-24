#include <iostream>
using namespace std;

#define MAX 100

class Deque{

    int arr[MAX];
    int rear;
    int front;
    int size;
public:
    Deque(int size){
        front = -1;
        rear = 0;
        this->size = size;
    }
    void insertfront(int);
    void insertrear(int);
    void deletefront();
    void deleterear();
    bool isFull();
    bool isEmpty();
};

bool Deque :: isFull(){
    return((front == 0 && rear == size -1) ||
    front == rear + 1);
}

bool Deque :: isEmpty(){
    return (front == -1); 
}
void Deque :: insertfront(int x)
{
    if(isFull()){
        cout<<"Queue is full\n";
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
    else if(front == 0){
        front = size - 1; // move front to last index
    }
    else front = front - 1;
    arr[front] = x;
}
void Deque :: insertrear(int x){
    if(isFull()){
        cout<<"Queue is full \n";
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
    else if(rear == size - 1){
        rear = 0;
    }
    else rear = rear + 1;
    arr[rear] = x;
}
void Deque :: deletefront()
{
    if(isEmpty()){
        cout<<"Queue is empty \n";
    }
    if(front == rear){
        front = rear = -1;
    }
    else {
        if(front == size - 1){
            front = 0;
        }
        else front = front + 1;
    }
}
void Deque :: deleterear()
{
    if(isEmpty()){
        cout<<"Queue Underflow \n";
    }
    if(front == rear){
        front = rear = -1;
    }
    else if(rear == 0){
        rear = size - 1;
    }
    else rear = rear - 1;
}
int main() {
   
   Deque dq(5);
   dq.insertrear(10);
   dq.insertrear(20);
   dq.deleterear();
   dq.insertfront(15);
   dq.deletefront();
   
}
