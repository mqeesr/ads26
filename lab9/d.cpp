#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> pref_func(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }

        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

string to_lower(string s){
    for(int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
    }
    return s;
}

int main(){
    string p; int n; cin >> p >> n;
    string low_p = to_lower(p);
    vector<string> nms(n);
    vector<int> over(n);
    int bst = 0;
    for(int i = 0; i < n; i++){
        cin >> nms[i];
        string s = to_lower(nms[i]) + "#" + low_p;
        vector<int> pi = pref_func(s);

        over[i] = pi[s.size() - 1];
        if(over[i] > bst) bst = over[i];
    }

    if(bst == 0){
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(over[i] == bst) cnt++;
    }

    cout << cnt << endl;
    for(int i = 0; i < n; i++){
        if (over[i] == bst) cout << nms[i] << endl;
    }
}