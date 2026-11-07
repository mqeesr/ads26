#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

int main() {
    string t, a;
    cin >> t >> a;

    int m = t.size();

    string s = t + "#" + a + a;
    vector<int> pi = prefix_function(s);

    for (int i = m + 1; i < s.size(); i++) {
        if (pi[i] == m) {
            cout << i - 2 * m << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}