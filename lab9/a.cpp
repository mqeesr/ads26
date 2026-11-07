#include <iostream>
#include <vector>
using namespace std;

vector<int> pref_func(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }

    return pi;
}

int main(){
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    int cop = (m + n - 1) / n + 1;
    string txt = "";
    for(int i = 0; i < cop; i++) txt += a;
    string s = b + "#" + txt;
    vector<int> pi = pref_func(s);
    for(int i = m + 1; i < s.size(); i++){
        if(pi[i] == m){
            int pos = i - 2 * m;
            int end = pos + m;
            cout << (end + n - 1) / n << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}