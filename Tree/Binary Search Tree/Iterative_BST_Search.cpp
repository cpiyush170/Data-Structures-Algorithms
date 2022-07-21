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
    newNode->left = newNode->right = NULL;
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

bool IterativeSearch(BstNode* root,int key){
   
   while(root != NULL){
   if(root->data == key) return true;
   else if(key < root->data) root = root->left;
   else root = root->right;
   }
   return false;
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
   if(IterativeSearch(root,number) == true)
   {

   cout << "Element found "<<endl;
   }
   else
   {
   cout << "Element not found "<<endl;
   }
}
