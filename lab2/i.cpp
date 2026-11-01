#include <iostream>
#include <string>
using namespace std;

struct Node{
    string ttl;
    Node* prev;
    Node* next;
    Node(string t){
        ttl = t;
        prev = nullptr;
        next = nullptr;
    }
};

struct DoublyLinkedList{
    Node* head = nullptr;
    Node* tail = nullptr;
    
    bool isEmpty(){
        return head == nullptr;
    }
    
    void add_front(string ttl){
        Node* newNode = new Node(ttl);
        if(isEmpty()) head = tail = newNode;
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "ok\n";
    }
    
    void add_back(string ttl){
        Node* newNode = new Node(ttl);
        if(isEmpty()) head = tail = newNode;
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "ok\n";
    }
    
    void erase_front(){
        if(isEmpty()){
            cout << "error\n";
            return;
        }
        cout << head->ttl << "\n";
        Node* temp = head;
        if(head == tail) head = tail = nullptr;
        else{
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    void erase_back(){
        if(isEmpty()){
            cout << "error\n";
            return;
        }
        cout << tail->ttl << "\n";
        Node* temp = tail;
        if(head == tail) head = tail = nullptr;
        else{
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }
    
    void front(){
        if(isEmpty()) cout << "error\n";
        else cout << head->ttl << "\n";
    }
    
    void back(){
        if(isEmpty()) cout << "error\n";
        else cout << tail->ttl << "\n";
    }
    
    void clear(){
        while(!isEmpty()){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "ok\n";
    }
};

int main(){
    DoublyLinkedList list;
    string command, ttl;
    
    while(cin >> command){
        if(command == "add_front"){
            cin >> ttl;
            list.add_front(ttl);
        } else if(command == "add_back"){
            cin >> ttl;
            list.add_back(ttl);
        } else if(command == "erase_front"){
            list.erase_front();
        } else if(command == "erase_back"){
            list.erase_back();
        } else if(command == "front"){
            list.front();
        } else if(command == "back"){
            list.back();
        } else if(command == "clear"){
            list.clear();
        } else if(command == "exit"){
            cout << "goodbye\n";
            break;
        }
    }
    return 0;
}