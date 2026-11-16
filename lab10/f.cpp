#include <iostream>
using namespace std;

int p[100001];
int find(int x){
    if(p[x] == x) return x;
    p[x] = find(p[x]);
    return p[x];
}

int main(){
    int n, m, x, y, s, f; cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;
    while(m--){
        cin >> x >> y;
        p[find(x)] = find(y);
    }
    cin >> s >> f;
    if(find(s) == find(f)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}