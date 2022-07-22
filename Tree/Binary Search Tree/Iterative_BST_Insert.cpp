#include <iostream>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int data;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *root = NULL;
void IterativeInsert(int key)
{
    Node *t = root;
    if(root == NULL){
        root = new Node(key);
        return;
    }
    Node *tail;
    while(t != NULL)
    {
        tail = t;

        if(key == t->data) return;
        else if(key < t->data) t = t->left;
        else t = t->right;
    }
    Node *newNode = new Node(key);
    if(newNode->data < tail->data) tail->left = newNode;
    else tail->right = newNode;

    
}
void InOrder(Node* root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        cout<<root->data<<" ";
        InOrder(root->right);
    }
}
int main() {
   
   IterativeInsert(30);
   IterativeInsert(20);
   IterativeInsert(40);

    InOrder(root);
}
