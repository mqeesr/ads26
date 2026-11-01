#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

bool splt(vector<ll>& a, ll maxSum, ll k){
    ll blocks = 1;
    ll cur = 0;
    int n = a.size();
    for(int i = 0; i < n; i++){
        if(cur + a[i] > maxSum){
            blocks = blocks + 1;
            cur = a[i];
        }
        else cur = cur + a[i];
    }
    return blocks <= k;
}

int main(){

    int n; ll k; cin >> n >> k;
    vector<ll> a(n);
    ll maxElem = 0;
    ll totalSum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > maxElem) maxElem = a[i];
        totalSum = totalSum + a[i];
    }
    ll lo = maxElem;
    ll hi = totalSum;
    while(lo < hi){
        ll mid = lo + (hi - lo) / 2;
        if(splt(a, mid, k)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << endl;
}