#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

typedef long long LL;
typedef long double LD;

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(),(v).end()

const int mod = 1e9 + 7;

int solve() {
    int n, d;
    cin >> n >> d;
    vector<int> l(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        sum += l[i];
    }
    sort(all(l));
    if (l[n - 1] + l[n - 2] > d) {
        return cout << "No" << endl, 0;
    }
    d -= l[n - 1] + l[n - 2];
    l.pop_back();
    l.pop_back();
    n -= 2;
    vector<bool> dp(d + 1);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = d; j >= 0; --j) {
            if (j - l[i] >= 0) {
                dp[j] = dp[j] | dp[j - l[i]];
            }
        }
    }
    cout << (dp[d] ? "Yes" : "No") << endl;
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
