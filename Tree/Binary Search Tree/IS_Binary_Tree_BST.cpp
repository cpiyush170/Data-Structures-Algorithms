#include <iostream>
#define INT_MIN -1000
#define INT_MAX 1000

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};
Node* GetNewNode(int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* Insert(Node *root, int data){
    if(root == NULL){
        root = GetNewNode(data);
    }
    else if(data <= root->data){
        root->left = Insert(root->left,data);
    }
    else
    root->right = Insert(root->right,data);

    return root;
}
bool IsBstUtil(Node *root, int minValue, int maxValue){
    
    if(root == NULL) return true;

    if(root->data > minValue && root->data < maxValue
    && IsBstUtil(root->left,minValue,root->data)
    && IsBstUtil(root->right,root->data, maxValue))
    return true;
    else
    return false;
}
bool IsBinarySearchTree(Node *root){

    return IsBstUtil(root,INT_MIN,INT_MAX);
}
int main() {
    Node *root = NULL;
    root = Insert(root,7);
    root = Insert(root,4);
    root = Insert(root,9);
    root = Insert(root,1);
    root = Insert(root,6);
    
   if(IsBinarySearchTree(root) == true)
   cout << "Given Binary tree is BST"<<endl;
   else
   cout << "Given Binary tree isn't BST"<<endl;
    

}
