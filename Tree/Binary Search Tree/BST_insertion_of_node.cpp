#include <iostream>
using namespace std;

struct BstNode{
    
    int data;
    BstNode* left;
    BstNode* right;
};
// utility function to create node
BstNode* GetNewNode(int val){
    BstNode *newNode = new BstNode();
    newNode->data = val;
    newNode->left =  newNode->right = NULL;
    return newNode;
}
BstNode* Insert(BstNode* root, int data){
    
    BstNode *newNode = GetNewNode(data);
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

bool Search(BstNode* root,int data){
    if(root == NULL) return false;
    if(data == root->data) return true;
    
    else if(data <= root->data)
     return Search(root->left,data);
    else return Search(root->right,data);
}
int main() {
   
   BstNode *root = NULL;
   root = Insert(root,15);
   root = Insert(root,10);
   root = Insert(root,20);
   root = Insert(root,8);
   root = Insert(root,12);
   root = Insert(root,17);
   root = Insert(root,20);
   
   cout << "Enter number to be searched"<<endl;
   int number;
   cin >>number;
   if(Search(root,number) == true)
   {

   cout << "Element found "<<endl;
   }
   else
   {
   cout << "Element not found "<<endl;
   }
}
