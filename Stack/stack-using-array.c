/* Stack implementation using Array */

#include <stdio.h>
#define size 5

int arr[size];
int top = -1;
int isStackFull(){
    if(top == size - 1)
    return 1;
    return 0;
}
// function to push element in stack
void push(int val){
    // checks if stack is full or not
    if(isStackFull()){
        printf("\nStack is Full \n");
    }
    else{
        // increment top
        top++;
        // push element into stack
        arr[top] = val;
    }
}

int isStackEmpty(){
    if(top == -1)
    return 1;
    return 0;
}
void pop(){
    //checks if stack is empty or not
    if(isStackEmpty()){
        printf("\nStack is empty \n ");
    }
    else{
        // print the popped element
        printf("\nPopped element is %d ",arr[top]);
        // decrement top by 1
        top--;
    }

}
void printStack(){
    printf("\n");
        printf("Stack is: ");
        // loop till top element of stack
    for(int i=0;i<=top;i++){
        printf("%d ",arr[i]);
    }
}
int main() {
    push(10);
    push(20);
    push(40);
    push(60);
    push(100);
    pop();
    printStack();
}
