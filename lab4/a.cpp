#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *left, *right;
};

Node *create_node(int value){
    Node *new_node = new Node;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(Node *root, int value){
    Node *current = root;
    int depth = 0;
    while(true){
        if(value <= current->value){
            if(current->left == NULL){
                if(depth + 1 <= 100) current->left = create_node(value);
                return;
            }
            current = current->left;
        }
        else{
            if(current->right == NULL){
                if(depth + 1 <= 100) current->right = create_node(value);
                return;
            }
            current = current->right;
        }
        depth += 1;
    }
}

int main(){

    int n, m; cin >> n >> m;
    int num; cin >> num;
    Node *root = create_node(num);
    for(int i = 1; i < n; i++){
        cin >> num;
        insert(root, num);
    }
    for(int i = 0; i < m; i++){
        string pth; cin >> pth;
        Node *current = root;
        for(int j = 0; j < pth.size(); j++){
            if(pth[j] == 'L') current = current->left;
            else current = current->right;
            if(current == NULL) break;
        }    
        if(current == NULL) cout << "NO" << endl;
        else cout << "YES" << endl;    
    }
}