#include <iostream>
#include <cassert>
#include <numeric>

using namespace std;

typedef long long LL;
typedef long double LD;

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(),(v).end()

const int mod = 1e9 + 7;

int solve() {
    LL a, b;
    cin >> a >> b;
    LL g = a / gcd(a, b) * b;
    cout << (b % a ? g : g * (b / a)) << endl;
    return 0;
}
#undef int
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
