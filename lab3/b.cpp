#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt(const vector<int> &a, int l, int r){
    if (l > r) return 0;
    return upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
}

int main(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    for(int i = 0; i < q; i++){

        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        int ans = cnt(a, l1, r1) + cnt(a, l2, r2) - cnt(a, max(l1, l2), min(r1, r2));
        cout << ans << endl;
    }
}