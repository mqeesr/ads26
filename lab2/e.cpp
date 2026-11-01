#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = nullptr;
    }
};

int main(){
    

    int n; cin >> n;
    
    if (n == 1) {
        int val; cin >> val;
        cout << endl;
        return 0;
    }

    int val; cin >> val;
    Node* head = new Node(val);
    Node* current = head;
    
    for(int i = 1; i < n; i++){
        cin >> val;
        current->next = new Node(val);
        current = current->next;
    }
    
    int mid = n / 2;
    current = head;
    for(int i = 0; i < mid - 1; i++){
        current = current->next;
    }
    
    Node* node_to_delete = current->next;
    current->next = current->next->next;
    
    current = head;
    bool first = true;
    while(current != nullptr){
        if(!first) cout << " ";
        cout << current->data;
        first = false;
        current = current->next;
    }
    cout << endl;
    
}