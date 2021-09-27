/*Program to search a given node in the Linked List*/

#include <iostream>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
// function to add the node at the last of the list
void addLast(node **head, int val){
    // creating a new node in the heap section
    node *newNode = (node*)malloc(sizeof(node));
    // assigning value to it and making as NULL
    newNode->data = val;
    newNode->next = NULL;
    // if list is empty, make newNode as head;
    if(*head == NULL){
        *head = newNode;
    }
    // otherwise, find the last node and make it point
    // to the newNode (to add newNode at the end of list)
    else{
        node *lastNode = *head;
        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        // adding the newNode at the end of linked list
        lastNode->next = newNode;
    }

}
int searchNode(node *head, int key){
    node *temp = head;
    while(temp != NULL){
        // if key found return 1
        if(temp->data == key)
        return 1;
        temp = temp->next;
    }
    //key not found
    return -1;
}
void printList(node *head){
    node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
using namespace std;
int main() {
    // creating a empty head pointer of type node (struct node)
    node *head = NULL;
    addLast(&head,10);
    addLast(&head,20);
    addLast(&head,30);
    printList(head);

    if(searchNode(head,30) == 1){
        printf("\nSearch Found\n");
    }
    else{
        printf("\nSearch Not Found\n");
    }
    
}
