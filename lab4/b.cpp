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
    int left_cnt = cnt(node->left);
    int right_cnt = cnt(node->right);
    return 1 + left_cnt + right_cnt;
}

int main(){
    
    int n; cin >> n;
    int num; cin >> num;
    Node *root = create_node(num);
    for(int i = 1; i < n; i++){
        cin >> num;
        insert(root, num);
    }
    int x; cin >> x;
    Node *cur = root;
    while(cur->val != x){
        if(x < cur->val) cur = cur->left;
        else cur = cur->right;
    }
    cout << cnt(cur) << endl;
}