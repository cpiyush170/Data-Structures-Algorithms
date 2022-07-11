/* Breadth First Approach - Traversing Tree level by level (Level Order Traversal) */
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;
};
Node* GetNewNode(char data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* Insert(Node *root, char data){
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
void LevelOrder(Node *root){
    if(root == NULL)  return; // if tree is empty
    queue<Node*> Q;
    Q.push(root); // enqueue operation

    while(!Q.empty()){
        // putting front of queue in current
        Node* current = Q.front(); 
        cout << current->data << " "; // printing front
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop(); // removing the element from front

    }
}
int main() {
    Node *root = NULL;
    root = Insert(root,'F');
    root = Insert(root,'A');
    root = Insert(root,'G');
    root = Insert(root,'H');
    root = Insert(root,'L');
    LevelOrder(root);
}
