// Height of tree = Height of root node
// Height of a node = Number of edges in longest path from that node to a leaf node.
// for any node, height of tree = is greater of height of its left subtree and height of its right subtree + 1 (for connecting root node to subtree)
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

int findHeight(BstNode* root){
    if(root == NULL)
    return -1;
    else{
        int left = findHeight(root->left);
        int right = findHeight(root->right);
        
        int height = (left<right) ? right+1: left+1;
        return height;
    }
}
int main() {
   
   BstNode *root = NULL;
   root = Insert(root,15);
   root = Insert(root,10);
   root = Insert(root,20);
   root = Insert(root,8);
   root = Insert(root,12);
   root = Insert(root,17);
   root = Insert(root,25);
 
   cout << findHeight(root) <<endl;
}
