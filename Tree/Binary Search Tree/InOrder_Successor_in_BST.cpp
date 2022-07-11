/* Find Inorder successor in a BST */

#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

//Function to find some data in the tree
Node* Find(Node *root,int data){

    if(root == NULL) return NULL;
    else if(root->data == data) return root;
    else if(root->data < data)
    return Find(root->right,data);
    else
    return Find(root->left,data);
}

//Function to find Node with minimum value in a BST
Node* FindMin(Node *root){
    if(root == NULL) return NULL;
    while(root->left != NULL) root = root->left;
    return root;
}

//Function to find Inorder Successor in a BST
struct Node* Getsuccessor(struct Node* root,int data) {

// search the node - O(h)
    Node* current = Find(root,data);
    if(current == NULL) return NULL;
    // if node has right subtree
    if(current->right != NULL){
        return FindMin(current->right);
    }
    else{
        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor != current){

            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}
 
//Function to visit nodes in Inorder
void Inorder(Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
 
// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
 
int main() {

	Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);

	//Print Nodes in Inorder
	cout<<"Inorder Traversal: ";
	Inorder(root);
	cout<<"\n";

	// Find Inorder successor of some node. 
	struct Node* successor = Getsuccessor(root,5);
	if(successor == NULL) cout<<"No successor Found\n";
	else
    cout<<"Successor is "<<successor->data<<"\n";
}
