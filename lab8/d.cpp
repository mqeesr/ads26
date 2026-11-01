#include <iostream>
#include <vector>
#include <string>
using ll = long long;
using namespace std;

vector<ll> p;

int main() {
    int n; cin >> n;
    p.resize(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    string s = "";
    for(int i = 0; i < n; i++){
        ll diff = p[i];
        if (i > 0) diff -= p[i - 1];
        ll val = diff / (1LL << i);
        s += (char)(val + 97);
    }
    cout << s << endl;
}