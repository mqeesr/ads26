#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> pi;
void prefix_function(const string &t){
    int n = t.size();
    pi.assign(n, 0);
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while (j > 0 && t[i] != t[j]) j = pi[j - 1];
        if (t[i] == t[j]) j++;
        pi[i] = j;
    }
}
int main(){
    int n;
    while(cin >> n){
        vector<string> pat(n);
        for (int i = 0; i < n; i++) cin >> pat[i];
        string text;
        cin >> text;

        vector<int> cnt(n, 0);
        int best = 0;

        for(int k = 0; k < n; k++){
            int m = pat[k].size();
            string t = pat[k] + "#" + text;
            prefix_function(t);
            for(int i = m + 1; i < (int)t.size(); i++){
                if (pi[i] == m) cnt[k]++;
            }
            if (cnt[k] > best) best = cnt[k];
        }

        cout << best << endl;
        for(int k = 0; k < n; k++){
            if(cnt[k] == best) cout << pat[k] << endl;
        }
    }
    return 0;
}