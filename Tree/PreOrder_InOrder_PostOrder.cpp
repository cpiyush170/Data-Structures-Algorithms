/* Depth First Strategy - completely visit a subtree before going to next child.
Types: <root> <left> <right> - PreOrder
        <left> <root> <right> - InOrder
         <left> <right> <root> - PostOrder */
#include <iostream>

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
void PreOrder(Node *root){

    if(root == NULL) return;

    cout << root->data <<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(Node *root){
    if(root == NULL) return;

    InOrder(root->left); //visit left subtree
    cout << root->data <<" "; // visit root
    InOrder(root->right); // then visit right subtree
}
void PostOrder(Node *root){
    if(root == NULL) return;

    PostOrder(root->left); //visit left subtree
    PostOrder(root->right); // then visit right subtree
    cout << root->data <<" "; // visit root
}
int main() {
    Node *root = NULL;
    root = Insert(root,'F');
    root = Insert(root,'D');
    root = Insert(root,'J');
    root = Insert(root,'B');
    root = Insert(root,'E');
    root = Insert(root,'G');
    root = Insert(root,'K');
    root = Insert(root,'A');
    root = Insert(root,'C');
    root = Insert(root,'I');
    PreOrder(root);
    cout << "\n";
    InOrder(root);
     cout << "\n";
    PostOrder(root);

}
