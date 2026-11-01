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

int cnt = 0, ans = -1;
void inorder(Node *node, int k){
    if(node == nullptr || ans != -1) return;
    inorder(node->left, k);
    cnt++;
    if(cnt == k){
        ans = node->val;
        return;
    }
    inorder(node->right, k);
}

int main(){
    int n, k; cin >> n >> k;
    int num; cin >> num;
    Node *root = create_node(num);
    for(int i = 1; i < n; i++){
        cin >> num;
        insert(root, num);
    }
    inorder(root, k);
    cout << ans << endl;
}