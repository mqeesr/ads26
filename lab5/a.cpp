#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> a;

int parent(int i){
    return (i - 1) / 2;
}
int left(int i){
    return 2 * i + 1;
}
int right(int i){
    return 2 * i + 2;
}

void insert(ll k){
    a.push_back(k);
    int id = a.size() - 1;

    while(id > 0 && a[id] < a[parent(id)]){
        swap(a[id], a[parent(id)]);
        id = parent(id);
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

ll extractMin(){

    ll root_value = a[0];
    swap(a[0], a[a.size() - 1]);
    a.pop_back();
    if(a.size() > 0) heapify(0);
    return root_value;
}

int main(){

    int n; ll x; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        insert(x);
    }

    ll total = 0;
    while(a.size() > 1){
        ll first = extractMin();
        ll second = extractMin();
        total += first + second;
        insert(first + second);
    }

    cout << total << endl;
}