#include <iostream>
#include <vector>
using namespace std;

vector<int> a, res;

int main(){
    int n; cin >> n;
    a.resize(n);
    res.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n - 1;
    for(int k = n - 1; k >= 0; k--) {
        if(a[l] * a[l] > a[r] * a[r]){
            res[k] = a[l] * a[l];
            l++;
        } else{
            res[k] = a[r] * a[r];
            r--;
        }
    }

    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
}