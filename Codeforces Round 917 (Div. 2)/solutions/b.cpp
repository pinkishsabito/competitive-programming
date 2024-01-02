#include <iostream>
#include <cassert>
#include <set>

using namespace std;

typedef long long LL;
typedef long double LD;

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(),(v).end()

const int mod = 1e9 + 7;

int solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> st;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        st.insert(s[i]);
        res += st.size();
    }
    cout << res << endl;
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
