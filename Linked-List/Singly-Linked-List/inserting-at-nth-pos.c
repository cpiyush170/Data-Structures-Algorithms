// Inserting node at the nth position 

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

// Function to insert node at the nth position
void Insert(int data, int n){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
  
    // if list is empty
    if( n == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
  
    struct node *temp = head;
    // first visit n-1 node 
    for(int i=1;i<n-1;i++){
        temp = temp->next;
    }
    // set address part of newly created node
    // as address of node next to node to be deleted
    newNode->next = temp->next;
    temp->next = newNode;
}

void PrintList(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}
int main() {
    head = NULL; // empty list
    Insert(2,1); // list: 2
    Insert(3,2); // list: 2,3
    Insert(4,1); // list: 4,2,3
    Insert(5,2); // list: 4,5,2,3
    PrintList(); // printing list
}
