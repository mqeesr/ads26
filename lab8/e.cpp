#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using ll = long long;
using namespace std;

vector<int> pi;
void pref_func(const string &t){
    int n = t.size();
    pi.assign(n, 0);
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while (j > 0 && t[i] != t[j]) j = pi[j - 1];
        if (t[i] == t[j]) j++;
        pi[i] = j;
    }
}

int main(){
    string s = ""; cin >> s;
    int n = s.size();
    ll ans = 0;
    for(int k = 1; k <= n; k++){
        string t = s.substr(0, k);
        reverse(t.begin(), t.end());
        pref_func(t);
        int mx = 0;
        for(int i = 0; i < k; i++) mx = max(mx, pi[i]);
        ans += k - mx;
    }
    cout << ans << endl;
}