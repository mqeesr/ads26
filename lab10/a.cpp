#include <iostream>
#include <queue>
using namespace std;

int a[1000][1000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int> > q;

int main(){
    int n, m, fr = 0; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) q.push(make_pair(i, j));
            if(a[i][j] == 1) fr++;
        }
    }

    int t = 0;
    while(!q.empty() && fr > 0){
        int sz = q.size();
        for(int k = 0; k < sz; k++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] == 1){
                    a[x1][y1] = 2;
                    fr--;
                    q.push(make_pair(x1, y1));
                }
            }
        }
        t++;
    }
    if(fr > 0) cout << -1 << endl;
    else cout << t << endl;
    return 0;
}