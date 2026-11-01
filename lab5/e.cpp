#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<long long> a;

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void insert(long long k) {
    a.push_back(k);
    int ind = a.size() - 1;

    while(ind > 0 && a[ind] < a[parent(ind)]) {
        swap(a[ind], a[parent(ind)]);
        ind = parent(ind);
    }
}

void heapify(int i){
    int n = a.size();
    if(left(i) >= n) return;

    int j = left(i);
    if(right(i) < n && a[right(i)] < a[left(i)]) j = right(i);

    if(a[i] > a[j]){
        swap(a[i], a[j]);
        heapify(j);
    }
}

int main() {
    int q, k;
    cin >> q >> k;

    long long sum = 0;
    string cmd;
    long long x;

    for(int i = 0; i < q; i++){
        cin >> cmd;
        if(cmd == "insert"){
            cin >> x;
            if((int)a.size() < k){
                insert(x);
                sum += x;
            } 
            else if (x > a[0]){
                sum -= a[0];
                a[0] = x;
                heapify(0);
                sum += x;
            }
        } 
        else cout << sum << endl;
    }

    return 0;
}