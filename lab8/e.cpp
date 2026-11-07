#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ull = unsigned long long;
vector<ull> hs;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        ull h = 0;
        for(int j = i; j < n; j++){
            h = h * 131 + s[j];
            hs.push_back(h);
        }
    }
    sort(hs.begin(), hs.end());
    cout << unique(hs.begin(), hs.end()) - hs.begin() << endl;
    return 0;
}