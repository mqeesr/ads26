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

int main(){
    int t; cin >> t;
    while (t--){
        string s; long long k; cin >> s >> k;
        long long n = s.size();
        vector<int> pi = pref_func(s);
        long long st = n - pi[n - 1];
        long long ans = n + (k - 1) * st;
        cout << ans << endl;
    }
    return 0;
}