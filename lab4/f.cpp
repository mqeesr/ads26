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

int cnt(Node *node){
    if(node == NULL) return 0;
    int cnt_lft = cnt(node->left);
    int cnt_rght = cnt(node->right);
    int h = 0;
    if(node->left != NULL && node->right != NULL) h = 1;
    return h + cnt_lft + cnt_rght;
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