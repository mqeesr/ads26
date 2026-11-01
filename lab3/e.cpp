#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long cntrng(vector<int> &a, int l, int r){
    if (l > r) return 0;
    int left = lower_bound(a.begin(), a.end(), l) - a.begin();
    int right = upper_bound(a.begin(), a.end(), r) - a.begin();
    return right - left;
}

int main(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    for (int i = 0; i < q; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        long long frst = cntrng(a, l1, r1);
        long long scnd = cntrng(a, l2, r2);
        int interL = max(l1, l2);
        int interR = min(r1, r2);
        long long bth = cntrng(a, interL, interR);
        long long answ = frst + scnd - bth;
        cout << answ << "\n";
    }
}