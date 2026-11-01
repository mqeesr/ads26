#include <iostream>
#include <vector>
using namespace std;

vector<int> a, tmp;
long long inv = 0;
void merge_sort(int l, int r){
    if(r - l <= 1) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m, r);

    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if(a[i] <= a[j]){
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
            inv += m - i;
        }
    }
    while(i < m) tmp[k++] = a[i++];
    while(j < r) tmp[k++] = a[j++];

    for(k = l; k < r; k++) a[k] = tmp[k];
}

int main(){
    int n; cin >> n;
    a.resize(n);
    tmp.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    merge_sort(0, n);
    cout << inv << endl;
}