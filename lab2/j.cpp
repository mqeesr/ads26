#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = nullptr;
    }
};

struct LinkedList{
    Node* head = nullptr;
    int size = 0;

    void insert(int x, int p){
        Node* newNode = new Node(x);
        if(p == 0){
            newNode->next = head;
            head = newNode;
        }
        else{
            Node* curr = head;
            for(int i = 0; i < p - 1; i++) curr = curr->next;
            newNode->next = curr->next;
            curr->next = newNode;
        }
        size++;
    }

    void remove(int p){
        if(head == nullptr) return;
        if(p == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else{
            Node* curr = head;
            for (int i = 0; i < p - 1; i++) curr = curr->next;
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        size--;
    }

    void print(){
        if(head == nullptr){
            cout << "-1\n";
            return;
        }
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->val << (curr->next == nullptr ? "" : " ");
            curr = curr->next;
        }
        cout << "\n";
    }

    void replace(int p1, int p2){
        if(p1 == p2) return;
        
        Node* extracted = nullptr;
        if(p1 == 0){
            extracted = head;
            head = head->next;
        }
        else{
            Node* curr = head;
            for (int i = 0; i < p1 - 1; i++) curr = curr->next;
            extracted = curr->next;
            curr->next = extracted->next;
        }
        
        if(p2 == 0){
            extracted->next = head;
            head = extracted;
        }
        else{
            Node* curr = head;
            for (int i = 0; i < p2 - 1; i++) curr = curr->next;
            extracted->next = curr->next;
            curr->next = extracted;
        }
    }

    void reverse(){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void cyclic_left(int x){
        if(size <= 1) return;
        x = x % size;
        if(x == 0) return;

        Node* tail = head;
        while(tail->next != nullptr) tail = tail->next;

        Node* newTail = head;
        for (int i = 0; i < x - 1; i++) newTail = newTail->next;

        tail->next = head;
        head = newTail->next;
        newTail->next = nullptr;
    }

    void cyclic_right(int x){
        if (size <= 1) return;
        x = x % size;
        if (x == 0) return;
        cyclic_left(size - x);
    }
};

int main(){
    
    LinkedList list;
    int cmnd;

    while(cin >> cmnd){
        if(cmnd == 0){
            break;
        } else if(cmnd == 1){
            int x, p;
            cin >> x >> p;
            list.insert(x, p);
        } else if(cmnd == 2){
            int p;
            cin >> p;
            list.remove(p);
        } else if(cmnd == 3){
            list.print();
        } else if(cmnd == 4){
            int p1, p2;
            cin >> p1 >> p2;
            list.replace(p1, p2);
        } else if(cmnd == 5){
            list.reverse();
        } else if(cmnd == 6){
            int x;
            cin >> x;
            list.cyclic_left(x);
        } else if(cmnd == 7){
            int x;
            cin >> x;
            list.cyclic_right(x);
        }
    }
    return 0;
}