#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ull = unsigned long long;
string s; int n;
vector<ull> h, pw;

ull get_hash(int l, int r){
    return h[r] - h[l] * pw[r - l];
}

int main(){
    cin >> s;
    n = s.size();
    h.assign(n + 1, 0);
    pw.assign(n + 1, 1);
    for(int i = 0; i < n; i++){
        h[i + 1] = h[i] * 131 + s[i];
        pw[i + 1] = pw[i] * 131;
    }

    int q; cin >> q;
    for(int k = 0; k < q; k++){
        int l, r; cin >> l >> r;
        int len = r - l + 1;
        ull target = get_hash(l - 1, r);
        int cnt = 0;
        for(int i = 0; i + len <= n; i++){
            if(get_hash(i, i + len) == target) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}