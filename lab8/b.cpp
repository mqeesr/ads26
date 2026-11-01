#include <iostream>
#include <vector>
#include <string>
using ll = long long;
using namespace std;

const ll P = 31;
const ll M1 = 1000000007;
const ll M2 = 998244353;
vector<ll> pw1, pw2;
vector<ll> h1a, h2a;   //pref hashes of s1 (mod M1, M2)
vector<ll> h1b, h2b;   //pref hashes of s2 (mod M1, M2)

void build_powers(int n) {
    pw1.assign(n + 1, 1);
    pw2.assign(n + 1, 1);
    for(int i = 1; i <= n; i++){
        pw1[i] = pw1[i - 1] * P % M1;
        pw2[i] = pw2[i - 1] * P % M2;
    }
}

void build_pref(const string &s, vector<ll> &h1, vector<ll> &h2){
    int n = s.size();
    h1.assign(n + 1, 0);
    h2.assign(n + 1, 0);
    for(int i = 0; i < n; i++){
        h1[i + 1] = (h1[i] * P + (s[i] - 'a' + 1)) % M1;
        h2[i + 1] = (h2[i] * P + (s[i] - 'a' + 1)) % M2;
    }
}
ll get1(const vector<ll> &h, int l, int len){
    return ((h[l + len] - h[l] * pw1[len]) % M1 + M1) % M1;
}

ll get2(const vector<ll> &h, int l, int len){
    return ((h[l + len] - h[l] * pw2[len]) % M2 + M2) % M2;
}

int main(){
    string s1, s2, t; cin >> s1 >> s2 >> t;

    int n1 = s1.size(), n2 = s2.size(), m = t.size();
    if(m > n1 || m > n2){
        cout << 0 << endl;
        return 0;
    }

    int mx = max(n1, max(n2, m));
    build_powers(mx);
    build_pref(s1, h1a, h2a);
    build_pref(s2, h1b, h2b);
    vector<ll> ht1, ht2;
    build_pref(t, ht1, ht2);
    ll t1 = get1(ht1, 0, m);
    ll t2 = get2(ht2, 0, m);
    int limit = min(n1, n2) - m;
    int cnt = 0;
    for(int i = 0; i <= limit; i++){
        bool ok1 = get1(h1a, i, m) == t1 && get2(h2a, i, m) == t2;
        bool ok2 = get1(h1b, i, m) == t1 && get2(h2b, i, m) == t2;
        if (ok1 && ok2) cnt++;
    }
    cout << cnt << endl;
}