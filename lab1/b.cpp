#include <iostream>
using namespace std;

int main(){

    long long a, n, m; cin >> a >> n >> m;

    if(m == 1){
        cout << 0 << endl;
        return 0;
    }

    long long res = 1;
    a = a % m;

    while(n > 0){

        if (n % 2 == 1) res = (res * a) % m;
        a = (a * a) % m;
        n = n / 2;
    }
    cout << res << endl;
}