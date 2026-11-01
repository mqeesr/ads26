#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<string, string> > a(n);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        a[i].first = s.substr(6, 4) + s.substr(3, 2) + s.substr(0, 2);
        a[i].second = s;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) cout << a[i].second << endl;
}