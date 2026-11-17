#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int a, b; cin >> a >> b;
    vector<int> d(20001, -1), p(20001, 0);
    queue<int> q;
    d[a] = 0;
    q.push(a);
    while(!q.empty()){
        int x = q.front(); q.pop();
        int nx[2] = {x * 2, x - 1};
        for(int i = 0; i < 2; i++){
            int y = nx[i];
            if(y >= 1 && y <= 20000 && d[y] == -1){
                d[y] = d[x] + 1;
                p[y] = x;
                q.push(y);
            }
        }
    }
    cout << d[b] << endl;
    vector<int> pth;
    for (int c = b; c != a; c = p[c]) pth.push_back(c);
    for (int i = pth.size() - 1; i >= 0; i--) cout << pth[i] << " ";
    cout << endl;
    return 0;
}