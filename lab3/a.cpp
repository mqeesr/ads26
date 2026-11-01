#include <iostream>
using namespace std;

int main(){

    int n;  cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int x;  cin >> x;
    int l = 0, r = n - 1;
    bool fnd = false;
    
    while(l <= r){
        int mid = (l + r) / 2; 
        
        if(a[mid] == x){
            fnd = true;
            break;
        } 
        else if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    
    if(fnd) cout << "Yes" << endl;
    else cout << "No" << endl;   
}