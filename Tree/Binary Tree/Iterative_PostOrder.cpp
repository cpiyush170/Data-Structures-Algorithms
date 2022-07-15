#include <iostream>
#include <stack>
// Algorithm 
// Iterative Postorder using two stacks //
/* 1. Push the root element to stack s1 
   2. loop while s1 is not emtpy 
   3. pop out node from s1 and push into s2 
   4. if left and right child of s2 node exist 
   push them into stack (first left, then right)
   5. repeat step 3 and 4 until s1 is not empty 
   6. the element inside s2 is your postorder traversal
   7. print them one by one */
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void IterativePostOrder(Node *t)
{
    stack<Node*> s1, s2;
    s1.push(t); // push root node 
    
    while(!s1.empty())
    {
        Node* poppedNode = s1.top(); s1.pop();
        s2.push(poppedNode);
        if(poppedNode->left != NULL){
            s1.push(poppedNode->left);
        }
        if(poppedNode->right != NULL){
            s1.push(poppedNode->right);
        }
    }
    while(!s2.empty()){
        Node *el = s2.top();
        s2.pop();
        cout<<el->data<<" ";
    }

}
int main() {
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(5);

    root->left->left = new Node(4);
    root->left->right = new Node(9);

    root->right->left = new Node(7);
    root->right->right = new Node(2);


    IterativePostOrder(root);
}
