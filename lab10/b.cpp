#include <iostream>
#include <queue>
using namespace std;

int g[100][100], d[100];
int main(){
    int n, s, t; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    cin >> s >> t;
    s--; t--;
    for(int i = 0; i < n; i++) d[i] = -1;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int y = 0; y < n; y++)
            if(g[x][y] == 1 && d[y] == -1){
                d[y] = d[x] + 1;
                q.push(y);
            }
    }
    cout << d[t] << endl;
    return 0;
}