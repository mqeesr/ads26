#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> answ(n); stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() >= a[i]) st.pop();

        if(st.empty()) answ[i] = -1;
        else answ[i] = st.top();
        st.push(a[i]);
    }

    for(int i = 0; i < n; i++) cout << answ[i] << " ";
    cout << endl;
}