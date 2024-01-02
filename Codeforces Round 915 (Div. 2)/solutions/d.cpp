#include <iostream>
#include <cassert>
#include <vector>
#include <deque>

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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    deque<pair<int, int>> d;
    vector<bool> was(n + 1);
    LL answer = 0;
    for (int i = 0, mex = 0; i < n; ++i) {
        was[a[i]] = true;
        while (was[mex]) {
            ++mex;
        }
        d.push_back({mex, 1});
        answer += mex;
    }
    LL sum = answer;
    for (int i = 0; i < n; ++i) {
        pair<int, int> now = {a[i], 0};
        sum -= d.front().first;
        --d.front().second;
        if (d.front().second == 0) {
            d.pop_front();
        }
        while (!d.empty() && d.back().first >= a[i]) {
            sum -= 1LL * d.back().first * d.back().second;
            now.second += d.back().second;
            d.pop_back();
        }
        d.push_back(now);
        d.push_back({n, 1});
        sum += 1LL * now.first * now.second + 1LL * n;
        answer = max(answer, sum);
    }
    cout << answer << endl;
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
