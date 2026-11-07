#include <iostream>
#include <vector>
using namespace std;

vector<int> pref_func(string &s){
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

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<int> pi = pref_func(s);
    int cnt = 0;
    for(int i = 1; 2 * i < n; i++){
        int len = 2 * i;
        int p = len - pi[len - 1];
        if (len % p == 0 && (len / p) % 2 == 0) cnt++;
    }

    cout << cnt << endl;
    return 0;
}