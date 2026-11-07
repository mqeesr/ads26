#include <iostream>
#include <vector>
using namespace std;

vector<int> pref_func(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s1, s2; cin >> s1 >> s2;
    string ptr = s1, txt = s2;
    if(s1.size() > s2.size()){
        ptr = s2;
        txt = s1;
    }
    string s = ptr + "#" + txt;
    vector<int> pi = pref_func(s);
    int m = ptr.size();
    vector<int> res;
    for(int i = m + 1; i < s.size(); i++){
        if(pi[i] == m) res.push_back(i - 2 * m + 1);
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}