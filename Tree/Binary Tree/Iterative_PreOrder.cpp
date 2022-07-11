#include <iostream>
#include <stack>
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

void IterativePreOrder(Node *t)
{
    stack<Node*> st;

    while(t != NULL || !st.empty())
    {
        if(t != NULL)
        {
            cout<<t->data<<" ";
            st.push(t);
            t = t->left;
        }
        else{
            t = st.top();
            st.pop();
            t = t->right;
        }
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


    IterativePreOrder(root);
}
