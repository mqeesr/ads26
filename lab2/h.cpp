#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
    long long val;
    Node* next;
    Node(long long v){
        val = v;
        next = nullptr;
    }
};

int main() {
    int n; cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i < n; i++){
        long long val;
        cin >> val;
        Node* newNode = new Node(val);
        
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    long long max_sum = head->val;
    long long current_sum = head->val;

    Node* current = head->next;
    while(current != nullptr){
        current_sum = max(current->val, current_sum + current->val);
        max_sum = max(max_sum, current_sum);
        current = current->next;
    }
    current = head;
    while(current != nullptr){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    cout << max_sum << "\n";
    return 0;
}