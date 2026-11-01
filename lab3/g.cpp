#include <iostream>
#include <vector>
#include <cstdio>
using ll = long long;
using dbl = double;
using namespace std;


ll cntpcs(vector<ll>& a, dbl lngth){
    ll cnt = 0;
    int n = a.size();
    for (int i = 0; i < n; i++){
        ll pcs = (ll)(a[i] / lngth);
        cnt = cnt + pcs;
    }
    return cnt;
}

int main(){
    int n; ll k; cin >> n >> k;

    vector<ll> a(n);
    ll maxLen = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > maxLen) maxLen = a[i];
    }

    dbl lo = 0.0;
    dbl hi = (dbl)maxLen;

    for(int m = 0; m < 100; m++){
        dbl mid = (lo + hi) / 2.0;
        ll pcs = cntpcs(a, mid);

        if(pcs >= k) lo = mid;
        else hi = mid;
    }

    printf("%.9f\n", lo);
}