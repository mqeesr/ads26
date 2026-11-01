#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> a, tmp;
void merge_sort(int l, int r){
    if(r - l <= 1) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m, r);

    int i = l, j = m, k = l;
    while(i < m && j < r){
        if (a[j].size() < a[i].size()) tmp[k++] = a[j++];
        else tmp[k++] = a[i++];
    }
    while(i < m) tmp[k++] = a[i++];
    while(j < r) tmp[k++] = a[j++];

    for(k = l; k < r; k++) a[k] = tmp[k];
}

int main() {
    int t; cin >> t;
    string line;
    getline(cin, line);

    while(t--){
        getline(cin, line);
        stringstream ss(line);
        a.clear();
        string w;
        while(ss >> w) a.push_back(w);
        tmp.resize(a.size());
        merge_sort(0, a.size());
        for(int i = 0; i < a.size(); i++){
            if (i > 0) cout << " ";
            cout << a[i];
        }
        cout << endl;
    }
}