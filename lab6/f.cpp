#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Student {
    string last, first;
    long long num, den;
};

vector<Student> v;

int gradeValue(string g) {
    if (g == "A+") return 16;
    if (g == "A") return 15;
    if (g == "B+") return 14;
    if (g == "B") return 12;
    if (g == "C+") return 10;
    if (g == "C") return 8;
    if (g == "D+") return 6;
    if (g == "D") return 4;
    return 0;
}

bool cmp(Student x, Student y) {
    long long l = x.num * y.den;
    long long r = y.num * x.den;
    if (l != r) return l < r;
    if (x.last != y.last) return x.last < y.last;
    return x.first < y.first;
}

int main() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> v[i].last >> v[i].first >> m;
        v[i].num = 0;
        v[i].den = 0;
        for (int j = 0; j < m; j++) {
            string g;
            int c;
            cin >> g >> c;
            v[i].num += (long long)gradeValue(g) * c;
            v[i].den += c;
        }
    }
    sort(v.begin(), v.end(), cmp);

    cout << fixed << setprecision(3);
    for (int i = 0; i < n; i++) {
        double gpa = (double)v[i].num / (4.0 * v[i].den);
        cout << v[i].last << " " << v[i].first << " " << gpa << endl;
    }
    return 0;
}