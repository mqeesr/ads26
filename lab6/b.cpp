#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    bool frst = true;
    while(i < n && j < m){
        if(a[i] < b[j]) i++;
        else if(a[i] > b[j]) j++;
        else{
            if(!frst) cout << " ";
            cout << a[i];
            frst = false;
            i++;
            j++;
        }
    }
    cout << endl;
}