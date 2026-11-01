#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int bst = a[1] - a[0];
    for(int i = 1; i + 1 < n; i++) bst = min(bst, a[i + 1] - a[i]);
    bool frst = true;
    for(int i = 0; i + 1 < n; i++){
        if(a[i + 1] - a[i] == bst){
            if(!frst) cout << " ";
            cout << a[i] << " " << a[i + 1];
            frst = false;
        }
    }
    cout << endl;
}