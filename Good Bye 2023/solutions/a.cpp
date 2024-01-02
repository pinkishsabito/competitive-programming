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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mult = 2023;
    for (int i = 0; i < n; ++i) {
        if (mult % a[i] != 0) {
            return cout << "NO" << endl, 0;
        }
        mult /= a[i];
    }
    cout << "YES" << endl;
    for (int i = 1; i < k; ++i) {
        cout << 1 << ' ';
    }
    cout << mult << endl;
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
