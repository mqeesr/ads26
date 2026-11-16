#include <iostream>
using namespace std;

char a[100][100];
int n, m;
void dfs(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || a[x][y] != '1') return;
    a[x][y] = '0';
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == '1'){
                dfs(i, j);
                cnt++;
            }
    cout << cnt << endl;
    return 0;
}