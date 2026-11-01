#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
};

Node *create_node(int val){
    Node *new_node = new Node;
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(Node *root, int val){
    Node *current = root;
    while(true){
        if(val < current->val){
            if(current->left == NULL){
                current->left = create_node(val);
                return;
            }
            current = current->left;
        }
        else{
            if(current->right == NULL){
                current->right = create_node(val);
                return;
            }
            current = current->right;
        }
    }
}

void preorder(Node *node){
    if(node == NULL) return;
    cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

int main(){
    int n; cin >> n;
    int num; cin >> num;
    Node *root = create_node(num);
    for(int i = 1; i < n; i++){
        cin >> num;
        insert(root, num);
    }
    int k; cin >> k;
    Node *cur = root;
    while(cur->val != k){
        if(k < cur->val) cur = cur->left;
        else cur = cur->right;
    }
    preorder(cur);
    cout << endl;
}