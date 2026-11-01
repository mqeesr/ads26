#include <iostream>
#include <string>
using namespace std;
int cnt[26];

int main(){
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
    string res = "";
    for(int i = 0; i < 26; i++) res += string(cnt[i], 'a' + i);
    cout << res << endl;
}