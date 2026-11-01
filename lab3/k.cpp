#include <iostream>
#include <algorithm>
using namespace std;

int a[800][800];
int q[10000];

int main(){

    int t; cin >> t;
    for(int i = 0; i < t; i++) cin >> q[i];
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int k = 0; k < t; k++){
        int x = q[k];
        bool found = false;
        for(int i = 0; i < n && !found; i++){
            int lo = min(a[i][0], a[i][m - 1]);
            int hi = max(a[i][0], a[i][m - 1]);
            if(x < lo || x > hi) continue;
            for(int j = 0; j < m; j++){
                if(a[i][j] == x){
                    cout << i << " " << j << "\n";
                    found = true;
                    break;
                }
            }
        }
        if(!found) cout << -1 << "\n";
    }
}