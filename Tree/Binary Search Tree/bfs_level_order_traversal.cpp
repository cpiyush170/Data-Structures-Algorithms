/*
Algorithm: 
There are basically two functions in this method. One is to print all nodes at a given level (printCurrentLevel)
and other is to print level order traversal of the tree (printLevelorder). 
printLevelorder makes use of printCurrentLevel to print nodes at all levels one by one starting from the root.

/*Function to print level order traversal of tree*/
printLevelorder(tree)
for d = 1 to height(tree)
   printCurrentLevel(tree, d);

/*Function to print all nodes at a current level*/
printCurrentLevel(tree, level)
if tree is NULL then return;
if level is 1, then
    print(tree->data);
else if level greater than 1, then
    printCurrentLevel(tree->left, level-1);
    printCurrentLevel(tree->right, level-1);


*/


#include <iostream>
using namespace std;

struct Node{

    int data;
    Node *left, *right;

    Node(int val){
        
       data = val;

       left = NULL;
       right = NULL;
    }
};

int height(Node *CurrentRoot){

    if(CurrentRoot == NULL) return 0;

// computing height of each subttree
    int l_height = height(CurrentRoot->left);
    int r_height = height(CurrentRoot->right);

// using larger subtree value + 1 for root
    if(l_height > r_height) return (l_height + 1);

    else return (r_height + 1);
}

void printCurrentLevel(Node *root, int level){
    
    if(root == NULL) return;

    if(level == 1) cout << root->data <<" ";
    
    else if(level > 1){
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}
// level order traversal
void printLevelOrder(Node *root){

    int h = height(root);
    int i;
    for(i=1; i<=h; i++){

        printCurrentLevel(root,i);
    }
}
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

cout << "Level Order traversal of binary tree \n";
    printLevelOrder(root);
}
