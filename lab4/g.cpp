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
    Node *cur = root;
    while(true){
        if(val == cur->val) return;
        else if(val < cur->val){
            if(cur->left == NULL){
                cur->left = create_node(val);
                return;
            }
            cur = cur->left;
        }
        else{
            if(cur->right == NULL){
                cur->right = create_node(val);
                return;
            }
            cur = cur->right;
        }
    }
}

int ans = 0;
int hgh(Node *node){
    if(node == NULL) return 0;
    int lft = hgh(node->left);
    int rght = hgh(node->right);
    if(lft + rght + 1 > ans) ans = lft + rght + 1; 
    if(lft > rght) return 1 + lft;
    return 1 + rght;
}

int main(){
    int n; cin >> n;
    int num; cin >> num;
    Node *root = create_node(num);
    for(int i = 1; i < n; i++){
        cin >> num;
        insert(root, num);
    }
    hgh(root);
    cout << ans << endl;
}