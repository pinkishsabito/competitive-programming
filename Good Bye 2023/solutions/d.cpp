#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;
typedef long double LD;

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(),(v).end()

const int mod = 1e9 + 7;

int solve() {
    int n;
    cin >> n;
    if (n == 1) {
        return cout << 1 << endl, 0;
    }
    string s = "1";
    for (int i = 0; i < n - 3; ++i) {
        s += "0";
    }
    s += "69";
    vector<string> answer;
    do {
        if (s[0] == '6') {
            continue;
        }
        if (answer.size() == n) {
            break;
        }
        int ptr = 1, cnt1 = 0, cnt2 = 0;
        while (s[ptr] == '0') {
            ++cnt1;
            ++ptr;
        }
        if (s[ptr] != '6') {
            continue;
        }
        ++ptr;
        while (s[ptr] == '0') {
            ++cnt2;
            ++ptr;
        }
        if (cnt1 == cnt2) {
            answer.push_back(s);
        }
    } while (next_permutation(all(s)));
    // if (sz(answer) != n) {
    //     cout << "qate #1" << endl;
    //     return 0;
    // }
    for (string i : answer) {
        cout << i << endl;
        // LL x = stoi(i);
        // LL root = sqrtl(x);
        // if (root * root != x) {
        //     cout << root << ' ' << root * root << ' ' << x << endl;
        //     cout << "qate #2" << endl;
        //     return 0;
        // }
    }
    cout << 196;
    for (int i = 0; i < n - 3; ++i) {
        cout << 0;
    }
    cout << endl;
    return 0;
}
int main() {
#ifdef LOCAL
    assert(freopen("../input.txt", "r", stdin));
    // assert(freopen("../output.txt", "w", stdout));
#endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
