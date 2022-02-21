#include <iostream>
using namespace std;

struct Node{
    
    int data;
    Node* left;
    Node* right;
};
// utility function to create node
Node* GetNewNode(int val){
    Node *newNode = new Node();
    newNode->data = val;
    newNode->left =  newNode->right = NULL;
    return newNode;
}
Node* Insert(Node* root, int data){
    
    Node *newNode = GetNewNode(data);
    // if tree is empty than assign newNode as root
    if(root == NULL)
    {
        root = newNode;
    }
// if data at root node is less than data to be inserted
// call Insert() recursively to put data into 
// left subtree
    else if( data <= root->data)
    {
        root->left = Insert(root->left,data);
    }
// or put data in right subtree
    else
    {
        root->right = Insert(root->right,data);
    }
    return root;
}
Node* findMin(Node *root){
    if(root->left == NULL) return root;

    return findMin(root->left);
}
Node* Delete(Node *root, int data){

    if(root == NULL) return root;

    else if(data < root->data) 
    root->left = Delete(root->left,data); // visit left subtree if key to find < current root node data
    else if(data > root->data)
    root->right = Delete(root->right,data); // else visit right subtree if key to find > current root node data
    else
    {   // case1: if it's leaf node (no child), if the node to be deleted is the leaf node, in such case simply delete the node from tree
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        // case 2: 1 child, If the node to deleted has single child node then follow the steps below :
        // 1. Replace that node with its child node.
        // 2. Remove the child node from its original position
        
        
        // if left of current root is Null(empty) make current root right
        else if(root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        
        // or right of currrent root is Null(empty) make current root left
        else if(root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // Third Case : The node to be deleted has two children, then follow the steps below:
        // 1. Get the inorder successor of that node
        // 2. Replace the node with the inorder successor.
        // 3. Remove the inorder successor from its original position
        
        // if current root has 2 children
        else{
            Node *temp = findMin(root->right); // getting inorder successor
            root->data = temp->data; // replace node to deleted value with inorder successor value
            root->right = Delete(root->right,temp->data); // calling delete function recursively to delete inorder successor from its original position
        }
    }
    return root;

}
void InOrder(Node *root){

    if(root == NULL) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
int main() {
   
   Node *root = NULL;
   root = Insert(root,15);
   root = Insert(root,10);
   root = Insert(root,20);
   root = Insert(root,8);
   root = Insert(root,12);
   root = Insert(root,17);
   root = Delete(root,17);
   InOrder(root);
   
}
