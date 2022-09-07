#include <iostream>
using namespace std;

// an AVL tree node
struct Node{
    int data;
    Node *left;
    Node *right;
    int height;
};


Node *root = NULL;

// utility function to create node
Node* GetNewNode(int val){
    Node *newNode = new Node();
    newNode->data = val;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int NodeHeight(struct Node *p){
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;
    
    return hl > hr ? hl + 1 : hr + 1;
}

int balanceFactor(struct Node *p){
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl - hr;
}
Node* LLRotation(struct Node *p){
    Node* pl = p->left;
    Node* plr = pl->right;

    pl->right = p;
    p->left = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == pl){
        root = pl;
    }
    return pl;
}
Node* LRRotation(Node *p){

    Node* pl = p->left;
    Node* plr = pl->right;
    
    pl->right = plr->left;
    p->left  = plr->right;

    plr->left = pl;
    plr->right = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root == p){
        root = plr;
    }
    return plr;
}
Node* RRRotation(Node *p){
    Node* pl = p->left;
    Node* plr = pl->right;

    pl->left = p;
    p->right = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

     if(root == pl){
        root = pl;
    }
    return pl;
}
Node* RLRotation(Node *p){
    Node* pr = p->right;
    Node* prl = pr->left;

    p->right = prl->left;
    pr->left = prl->right;

    prl->left = p;
    prl->right = pr;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if(root == p){
        root = prl;
    }
    return prl;

}
Node* Insert(Node *p, int data){

    Node *newNode = GetNewNode(data);

// if tree is empty than assign newNode as root
    if(p == NULL){
        p = newNode;
    }
    else if(data <= p->data){
        p->left = Insert(p->left, data);
    }
    else{
        p->right = Insert(p->right, data);
    }
    p->height = NodeHeight(p);

    if(balanceFactor(p) == 2 && balanceFactor(p->left) == 1){
        return LLRotation(p);
    }
    else if(balanceFactor(p) == 2 && balanceFactor(p->left) == -1){
        return LRRotation(p);
    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->right) == -1){
        return RRRotation(p);
    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->right) == 1){
        return RLRotation(p);
    }
    return p;
}

void PreOrder(Node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
int main() {
    root = Insert(root, 20);
    Insert(root, 30);
    Insert(root, 25);

    PreOrder(root);
}
