#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    int t; cin >> t;
    while(t--){

        int n; cin >> n;

        queue<char> q;

        vector<int> count(26, 0);
        for(int i = 0; i < n; i++){
            char c; cin >> c;

            count[c - 'a']++;
            q.push(c);

            while(!q.empty() && count[q.front() - 'a'] > 1) q.pop();

            if(q.empty()) cout << -1;
            else cout << q.front();

            if(i < n - 1) cout << " ";
        }
        cout << endl;
    }
    
}