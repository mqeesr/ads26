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
    
    Node* head1 = nullptr;
    if(n > 0){
        int val; cin >> val;
        head1 = new Node(val);
        Node* current = head1;
        for(int i = 1; i < n; i++){
            cin >> val;
            current->next = new Node(val);
            current = current->next;
        }
    }
    
    int m; cin >> m;
    Node* head2 = nullptr;
    if(m > 0){
        int val; cin >> val;
        head2 = new Node(val);
        Node* current = head2;
        for(int i = 1; i < m; i++){
            cin >> val;
            current->next = new Node(val);
            current = current->next;
        }
    }
    
    if(n == 0 && m == 0){
        cout << endl;
        return 0;
    }

    Node* mrghd = nullptr;
    
    if(head1 == nullptr) mrghd = head2;
    else if(head2 == nullptr) mrghd = head1;
    else{
        if(head1->data <= head2->data){
            mrghd = head1;
            head1 = head1->next;
        }
        else{
            mrghd = head2;
            head2 = head2->next;
        }
        
        Node* current = mrghd;
        while(head1 != nullptr && head2 != nullptr){
            if(head1->data <= head2->data){
                current->next = head1;
                head1 = head1->next;
            }
            else{
                current->next = head2;
                head2 = head2->next;
            }
            current = current->next;
        }
        
        if(head1 != nullptr) current->next = head1;
        if(head2 != nullptr) current->next = head2;
    }
    
    Node* current = mrghd;
    bool first = true;
    while(current != nullptr){
        if(!first) cout << " ";
        cout << current->data;
        first = false;
        current = current->next;
    }
    cout << endl;
}