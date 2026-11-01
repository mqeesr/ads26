#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[100][100];

int main(){
   int n, m; cin >> n >> m;
   for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cin >> a[i][j];
   }

    for(int j = 0; j < m; j++){
        vector<int> col(n);
        for (int i = 0; i < n; i++) col[i] = a[i][j];
        sort(col.begin(), col.end());
        for (int i = 0; i < n; i++) a[i][j] = col[n - 1 - i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
            if (j + 1 < m) cout << " ";
        }
        cout << endl;
    }
    return 0;
}