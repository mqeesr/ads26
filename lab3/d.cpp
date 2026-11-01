#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> cnt(10000 + 1, 0);
    vector<long long> sum(10000 + 1, 0);

    for(int i = 0; i < n; i++){
        int power = a[i];
        cnt[power] = cnt[power] + 1;
        sum[power] = sum[power] + power;
    }

    for(int v = 1; v <= 10000; v++){
        cnt[v] = cnt[v] + cnt[v - 1];
        sum[v] = sum[v] + sum[v - 1];
    }

    int p; cin >> p;

    for(int i = 0; i < p; i++){
        int m; cin >> m;
        cout << cnt[m] << " " << sum[m] << endl;
    }
}