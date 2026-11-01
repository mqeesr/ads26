#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
};

Node *create_node(int val){
    Node *new_node = new Node;
    new_node->val = val;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
}

void insert(Node *cur, int val){
    while(true){
        if(val < cur->val){
            if(cur->left == nullptr){
                cur->left = create_node(val);
                return;
            }
            cur = cur->left;
        }
        else{
            if(cur->right == nullptr){
                cur->right = create_node(val);
                return;
            }
            cur = cur->right;
        }
    }
}

int cnt(Node *node){
    if(node == nullptr) return 0;
    if(node->left == nullptr && node->right == nullptr) return 1;
    int lft = cnt(node->left);
    int rght = cnt(node->right);
    return lft + rght;
}

int main(){

    int n; cin >> n;
    int num; cin >> num;
    Node *root = create_node(num);
    for(int i = 1; i < n; i++){
        cin >> num;
        insert(root, num);
    }
    cout << cnt(root) << endl;
}