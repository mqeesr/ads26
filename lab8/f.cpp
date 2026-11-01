#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s; int n;
vector<vector<int>> ans;

void precom(){
    ans.assign(n, vector<int>(n + 2, 0));
    vector<int> prev(n + 2, 0), cur(n + 2, 0);
    for(int i = n - 1; i >= 0; i--){
        vector<int> c(n + 2, 0);
        for(int j = n - 1; j >= 0; j--){
            if (s[i] == s[j]) cur[j] = prev[j + 1] + 1;
            else cur[j] = 0;
            c[cur[j]]++;
        }
        int running = 0;
        for(int len = n; len >= 1; len--){
            running += c[len];
            ans[i][len] = running;
        }
        swap(prev, cur);
    }
}

int main(){
    cin >> s;
    n = s.size();
    precom();
    int q; cin >> q;
    for(int k = 0; k < q; k++){
        int l, r; cin >> l >> r;
        cout << ans[l - 1][r - l + 1] << "\n";
    }
    return 0;
}