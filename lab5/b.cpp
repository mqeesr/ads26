#include <iostream>
#include <vector>
using namespace std;
vector<long long> a;

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

void insert(long long k){
    a.push_back(k);
    int ind = a.size() - 1;

    while(ind > 0 && a[ind] > a[parent(ind)]){
        swap(a[ind], a[parent(ind)]);
        ind = parent(ind);
    }
}

void heapify(int i){
    int n = a.size();
    if(left(i) >= n) return;

    int j = left(i);
    if(right(i) < n && a[right(i)] > a[left(i)]) j = right(i);

    if(a[i] < a[j]){
        swap(a[i], a[j]);
        heapify(j);
    }
}

long long extractMax(){
    long long root_value = a[0];
    swap(a[0], a[a.size() - 1]);
    a.pop_back();
    if(a.size() > 0) heapify(0);

    return root_value;
}

int main(){
    int n;
    long long x;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        insert(x);
    }

    while(a.size() > 1){
        long long first = extractMax();
        long long second = extractMax();
        if(first != second) insert(first - second);
    }

    if(a.size() == 0) cout << 0 << endl;
    else cout << a[0] << endl;

    return 0;
}