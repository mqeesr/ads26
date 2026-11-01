#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n, k; cin >> n >> k;
    vector<int> m(n);
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        m[i] = max(x2, y2);
    }
    sort(m.begin(), m.end());
    cout << m[k - 1] << "\n";
}