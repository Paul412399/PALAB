#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;
};

struct Compare{
    bool operator()(Node *a, Node *b){
        return a->value > b->value;
    }
};

void printTree(Node* root, int depth = 0) {
    if (root == nullptr) return;
    
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++) {
        cout << "    "; 
    }
    cout << root->value << endl;
    printTree(root->left, depth + 1);
}

int calculLEP(Node *root){
    if(root->left){
        return root->value + calculLEP(root->left) + calculLEP(root->right);
    }
    return 0;
}

int main(){
    priority_queue<Node *, vector<Node *>, Compare> B;
    int n;
    cin >> n;
    int val;
    Node *nod;
    for(int i = 0; i < n; i++){
        cin >> val;
        nod = new Node;
        nod->value = val;
        nod->left = nullptr;
        nod->right = nullptr;
        B.push(nod);
    }
    while(B.size() > 1){
        Node *t1 = B.top();
        B.pop();
        Node *t2 = B.top();
        B.pop();
        Node *t = new Node;
        t->value = t1->value + t2->value;
        t->left = t1;
        t->right = t2;
        B.push(t);
    }

    Node *root = B.top();
    printTree(root);
    int LEP = calculLEP(root);
    cout<<"\nLEP = "<<LEP;
    return 0;
}