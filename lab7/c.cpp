#include <iostream>
#include <vector>
using namespace std;

struct Row{
    vector<int> v;
    int sum;
};
vector<Row> a, tmp;
bool before(const Row &x, const Row &y) {
    if (x.sum != y.sum) return x.sum > y.sum;
    return x.v < y.v;
}

void merge_sort(int l, int r){
    if(r - l <= 1) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m, r);

    int i = l, j = m, k = l;
    while(i < m && j < r){
        if (before(a[j], a[i])) tmp[k++] = a[j++];
        else tmp[k++] = a[i++];
    }
    while(i < m) tmp[k++] = a[i++];
    while(j < r) tmp[k++] = a[j++];

    for(k = l; k < r; k++) a[k] = tmp[k];
}

int main(){
    int n, m; cin >> n >> m;
    a.resize(n);
    tmp.resize(n);
    for(int i = 0; i < n; i++){
        a[i].v.resize(m);
        a[i].sum = 0;
        for(int j = 0; j < m; j++){
            cin >> a[i].v[j];
            a[i].sum += a[i].v[j];
        }
    }

    merge_sort(0, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i].v[j] << " ";
        }
        cout << endl;
    }
}