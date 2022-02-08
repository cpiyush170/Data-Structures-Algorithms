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
    root->left = Delete(root->left,data);
    else if(data > root->data)
    root->right = Delete(root->right,data);
    else
    {   // case1: if it's leaf node (no child)
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        // case 2: 1 child
        // if left of current root is Null
        else if(root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        // or right of currrent root is Null
        else if(root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // if current root has 2 children
        else{
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
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
