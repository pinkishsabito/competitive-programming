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
    int n;
    cin >> n;
    vector<int> a(n);
    int neg = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        neg += (a[i] < 0);
        zero += (a[i] == 0);
    }
    if (zero || neg % 2 == 1) {
        cout << "0" << endl;
    }
    else {
        cout << "1\n1 0" << endl;
    }
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
