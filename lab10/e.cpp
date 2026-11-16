#include <iostream>
using namespace std;

int a[1000][1000];
int n, q, x, y, z;

int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < q; i++){
        cin >> x >> y >> z;
        x--; y--; z--;
        if(a[x][y] == 1 && a[x][z] == 1 && a[y][z] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}