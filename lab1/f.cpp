#include <iostream>
#include <string>
using namespace std;

string func(string s){

    string res;
    for(int i = 0; i < s.length(); i++){

        if(s[i] == '#'){
            if(!res.empty()) res.pop_back();
        }else res.push_back(s[i]);
    }
    return res;
}

int main(){

    string a, b; cin >> a >> b;

    if(func(a) == func(b)) cout << "Yes" << endl;
    else cout << "No" << endl;
}