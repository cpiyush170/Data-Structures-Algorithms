#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){ top = NULL;}
    void push(int x);
    int pop();
    void Display();
};
void Stack :: push(int x)
{
    Node *newNode = new Node();
    if(newNode == NULL) cout<<"Stack is full\n";
    else{
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }
}
int Stack :: pop()
{   int x = -1;
    if(top == NULL) cout<<"Stack is empty\n";
    else{
        x = top->data;
        Node *temp = top;
        top = top->next;
        delete (temp);
    }
    return x;
}
void Stack :: Display()
{
    Node *temp = top;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
int main() {
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.Display();
    cout<<stk.pop()<<endl;
    stk.Display();

}
