#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n, m; cin >> n >> m;

    vector<long long> p(n);
    long long sum = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        sum += a;
        p[i] = sum;
    }

    for(int i = 0; i < m; i++){
        long long b; cin >> b;
        int idx = lower_bound(p.begin(), p.end(), b) - p.begin();
        cout << idx + 1 << "\n";
    }
}