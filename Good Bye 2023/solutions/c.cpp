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
    int odds = 0;
    vector<LL> ans;
    LL sum = 0;
    for (int i = 0, order = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            sum += a[i];
        }
        else {
            if (odds % 3 == 1) {
                sum += a[i] + 1;
            }
            else {
                sum += a[i] - 1;
            }
            ++odds;
        }
        cout << (i == 0 ? a[i] : sum) << ' ';
        ans.push_back(sum);
    }
    ans[0] = a[0];
    for (int i : ans) {
        cout << i << ' ';
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
