#include <iostream>
#include <string>

using namespace std;

struct Node{
    string word;
    Node* next;
    
    Node(string w){
        word = w;
        next = nullptr;
    }
};

int main(){
    int n, k; cin >> n >> k;

    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i < n; i++){
        string w; cin >> w;
        Node* newNode = new Node(w);
        
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        } 
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    if(k > 0 && k < n){
        Node* current = head;
        for(int i = 1; i < k; i++) current = current->next;

        Node* newTail = current;
        Node* newHead = current->next;
        tail->next = head;
        head = newHead;
        newTail->next = nullptr;
    }
    Node* current = head;
    while(current != nullptr){
        cout << current->word << " ";
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    cout << "\n";

    return 0;
}