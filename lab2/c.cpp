#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    
    int n; cin >> n;
    
    vector<string> vec;
    string prev = "";
    
    for(int i = 0; i < n; i++){
        string cur;
        cin >> cur;
        
        if(i == 0 || cur != prev){
            vec.push_back(cur);
            prev = cur;
        }
    }
    
    cout << vec.size() << endl;
    
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << endl;
    
}