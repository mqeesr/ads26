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

Node *nodes[1001];
int cnt[1001];

void dfs(Node *node, int depth){
    if(node == NULL) return;
    cnt[depth]++;
    dfs(node->left, depth + 1);
    dfs(node->right, depth + 1);
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) nodes[i] = create_node(i);
    for(int i = 0; i < n - 1; i++){
        int x, y, z; cin >> x >> y >> z;
        if(z == 0) nodes[x]->left = nodes[y];
        else nodes[x]->right = nodes[y];
    }
    dfs(nodes[1], 0);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(cnt[i] > ans) ans = cnt[i];
    }
    cout << ans << endl;
}