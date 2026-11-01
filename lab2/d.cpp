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
    
    int val; cin >> val;
    Node* head = new Node(val);
    Node* current = head;
    
    for(int i = 1; i < n; i++){
        cin >> val;
        current->next = new Node(val);
        current = current->next;
    }
    
    Node* prev = nullptr;
    current = head;
    Node* next_node = nullptr;
    
    while(current != nullptr){
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    head = prev;
    
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