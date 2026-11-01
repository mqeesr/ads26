#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

ll hrs(vector<ll>& bags, ll k){
    ll ttl = 0;
    int n = bags.size();
    for(int i = 0; i < n; i++){
        ll b = bags[i];
        ll need = (b + k - 1) / k;
        ttl = ttl + need;
    }
    return ttl;
}

int main(){
    int n; ll h; cin >> n >> h;

    vector<ll> bags(n);
    ll maxBag = 0;
    for(int i = 0; i < n; i++){
        cin >> bags[i];
        if(bags[i] > maxBag) maxBag = bags[i];
    }

    ll lo = 1;
    ll hi = maxBag;

    while(lo < hi){
        ll mid = lo + (hi - lo) / 2;
        ll hoursForMid = hrs(bags, mid);

        if(hoursForMid <= h) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << endl;
}