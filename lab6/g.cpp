#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    map<string, string> cur;
    for(int i = 0; i < n; i++){
        string o, nw; cin >> o >> nw;
        if(cur.count(o)){
            cur[nw] = cur[o];
            cur.erase(o);
        } else cur[nw] = o;
    }
    vector<pair<string, string> > res;
    for(map<string, string>::iterator it = cur.begin(); it != cur.end(); it++){
        res.push_back(make_pair(it->second, it->first));
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(int i = 0; i < (int)res.size(); i++) cout << res[i].first << " " << res[i].second << endl;
}