#include <iostream>
using namespace std;

int main(){
    long long a, b; cin >> a >> b;

    while(b != 0){
        long long c = a % b;
        a = b;
        b = c;
    }
    cout << a << endl;
}