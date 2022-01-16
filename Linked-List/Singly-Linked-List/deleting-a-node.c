/* Deleting a node from linked list */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
// function to add node
void addLast(node **head, int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        node *lastNode = *head;
        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}
// function to delete node
void delNode(node **head, int key){
    
    // temp is used to freeing the memory
    node *temp;
    // if you want to delete head node - first node
    if((*head)->data == key){
        // keep head in temp (backup)
        temp = *head;
        // make head point to next of head (second node)
        *head = (*head)->next;
        // delete first node
        free(temp);

    }
    // case 2: delete nth node in list
    else{
        node *current = *head;
        while(current->next != NULL){
            // node next to current node has data
            // part equal to node to be deleted
            if(current->next->data == key){
                // backup reference to next node
                temp = current->next;
                // modify reference of current's next (address) part
                current->next = current->next->next;
                free(temp);
                break;
            }
            else{
                // otherwise keep traversing 
                current = current->next;
            }
        }
    }

    }
    // function to printList 
void printList(node *head){
    node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    node *head = NULL;
    addLast(&head,10);
    addLast(&head,20);
    addLast(&head,30);
    addLast(&head,40);
    addLast(&head,50);
    printf("List before deletion: ");
    printList(head);
    delNode(&head,50);
    printf("List after deletion: ");
    printList(head);
}
