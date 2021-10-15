/* Queue data structure implementation using array */

#include <stdio.h>
#define size 5

// declare array
int arr[size];

// intialize front and rear as 0 
// which indicates that queue is empty intially
int front = 0;
int rear = 0;

// it will check whether the queue is empty or not
int isQueueEmpty(){
    if(front == rear)
    return 1;
    return 0;
}

// removes the current beginning element from queue(FIFO)
void dequeue(){
    if(isQueueEmpty() == 1)
    printf("Queue is empty \n.");
    else{
        printf("Dequeued element is %d \n", arr[front]);
        front++;
    }
}

// checks whether queue is full or not
int isQueueFull(){
    if(rear == size)
    return 1;
    return 0;
}

// add the element at the end of queue
void enqueue(int val){
    if(isQueueFull() == 1)
    printf("Queue is full \n");
    else{
        arr[rear] = val; // add at current rear
        rear++; // increment rear to point to next empty slot
    }
}

void printQueue(){
    printf("\n Queue is: ");
    for(int i=front;i<rear;i++){
        printf("%d ",arr[i]);
    }
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    
   printQueue();

    
}
