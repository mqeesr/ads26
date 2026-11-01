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
    
    if(n <= 0) return 0;
    
    int val; cin >> val;
    Node* head = new Node(val);
    Node* current = head;
    
    for(int i = 1; i < n; ++i){
        cin >> val;
        current->next = new Node(val);
        current = current->next;
    }
    
    Node* curr = head;
    bool firstelem = true;

    while(curr != nullptr){
        if(!firstelem) cout << " ";
        cout << curr->data;
        firstelem = false;
        
        if (curr->next != nullptr) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        
        curr = curr->next;
    }
    cout << endl;
    
}