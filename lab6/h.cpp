#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n; cin >> n;
    vector<char> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    char k; cin >> k;

    for(int i = 0; i < n; i++){
        if(a[i] > k){
            cout << a[i] << endl;
            return 0;
        }
    }
    cout << a[0] << endl;
}