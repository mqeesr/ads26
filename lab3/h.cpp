#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){

    int n; ll k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int lft = 0, best = n + 1; ll sum = 0;
    for(int rght = 0; rght < n; rght++){
        sum = sum + a[rght];
        while(lft <= rght && sum >= k){
            int wndL = rght - lft + 1;
            if (wndL < best){
                best = wndL;
            }
            sum -= a[lft];
            lft += 1;
        }
    }
    cout << best << endl;
}