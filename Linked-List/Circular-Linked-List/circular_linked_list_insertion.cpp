#include <iostream>
using namespace std;
// Implementation of Circular Linked List
struct Node{
    int data;
    Node *next;
};

Node *addToEmpty(Node *last, int data){

    if(last != NULL)
    return last;

    // create node dynamically
    Node *newNode = new Node();
    // assigning data
    newNode->data = data;
    last = newNode; // now last points to newNode
    // linking single node to itself
    newNode->next = last;
    return last;
}
Node *addBegin(Node *last, int data){
    if(last == NULL)
    return addToEmpty(last, data);
    
    // create node dynamically
    Node *newNode = new Node();
    // assigning data
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;

    return last;
}
Node *addEnd(Node *last, int data){
    if(last == NULL)
    return addToEmpty(last, data);
    
    // create node dynamically
    Node *newNode = new Node();
    // assigning data
    newNode->data = data;

    newNode->next = last->next;
    last->next = newNode;
    last = newNode;

    return last;
}
void printCLL(Node *last){
    // assiging first node to p
    Node *p = last->next;

    do
    {
        cout << p->data << " ";
        p = p->next;
    }
    while( p != last->next ); // iterate till last->next
// (first node) is not equal to p (last->next (first node))
}
struct Node *addAfter(struct Node *last, int data, int item)
{
	if (last == NULL)
	return NULL;

	struct Node *temp, *p;
	p = last -> next;

	// Searching the item.
	do
	{
		if (p ->data == item)
		{
			// Creating a node dynamically.
			temp = (struct Node *)malloc(sizeof(struct Node));

			// Assigning the data.
			temp -> data = data;

			// Adjusting the links.
			temp -> next = p -> next;

			// Adding newly allocated node after p.
			p -> next = temp;

			// Checking for the last node.
			if (p == last)
				last = temp;

			return last;
		}
		p = p -> next;
	} while (p != last -> next);

	cout << item << " not present in the list." << endl;
	return last;
}

int main() {
    Node *last = NULL;
    last = addToEmpty(last,67);
    last = addBegin(last,30);
    last = addEnd(last,85);
     last = addAfter(last, 10, 67);
    printCLL(last);
}
