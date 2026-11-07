#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ull = unsigned long long;
const ull B = 131;

int cnt_occur(const string &p, const string &s){
    int m = p.size(), n = s.size();
    if(m > n) return 0;
    ull hp = 0, hs = 0, pw = 1;
    for(int i = 0; i < m; i++){
        hp = hp * B + p[i];
        hs = hs * B + s[i];
        if(i > 0) pw *= B;
    }
    int res = 0;
    if(hs == hp) res++;
    for(int i = m; i < n; i++){
        hs = (hs - s[i - m] * pw) * B + s[i];
        if(hs == hp) res++;
    }
    return res;
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0) break;
        vector<string> pat(n);
        for(int i = 0; i < n; i++) cin >> pat[i];
        string text;
        cin >> text;
        vector<int> cnt(n, 0);
        int best = 0;
        for(int k = 0; k < n; k++){
            cnt[k] = cnt_occur(pat[k], text);
            if (cnt[k] > best) best = cnt[k];
        }
        cout << best << endl;
        for(int k = 0; k < n; k++){
            if(cnt[k] == best) cout << pat[k] << endl;
        }
    }
    return 0;
}