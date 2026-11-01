#include <iostream>
using namespace std;

int main(){
    int n; string s; cin >> n >> s;
    int cnt[26] = {0};
    for(int i = 0; i < n; i++) cnt[s[i] - 'a']++;
    string vwls = "aeiou";
    for(int i = 0; i < 5; i++){
        int c = vwls[i] - 'a';
        for(int j = 0; j < cnt[c]; j++) cout << vwls[i];
    }
    for(int c = 0; c < 26; c++){
        char ch = 'a' + c;
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') continue;
        for(int j = 0; j < cnt[c]; j++) cout << ch;
    }
    cout << endl;
}