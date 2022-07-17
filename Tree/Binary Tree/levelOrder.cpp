#include <iostream>
#include <queue>
using namespace std;

/*Algorithm: For level order traversal 

1. print root data
2. enqueue root's address into queue
3. dequeue queue and if
4. left child isn't empty print data and push it back into queue
5. right chld isn't empty print data and push it back into queue
6. repeat step 3, 4, and 5 until queue isn't empty
*/
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
void LevelOrder(Node *root)
{
    queue<Node*> q;

    cout<<root->data<<" "; // print root data
    q.push(root); 

    while(!q.empty())
    {
        root = q.front();
        if(root->left != NULL){
            cout<<root->left->data<<" ";
            q.push(root->left);
        }
        if(root->right != NULL){
            cout<<root->right->data<<" ";
            q.push(root->right);
        }
        q.pop();
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
    LevelOrder(root);
}
