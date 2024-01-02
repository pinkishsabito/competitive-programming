#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int a[maxn];

struct node {
    int odd;
    int even;
} t[30][maxn << 2];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        for (int i = 0; i < 30; ++i) {
            t[i][v].odd = a[tl] >> i & 1;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    for (int i = 0; i < 30; ++i) {
        t[i][v].odd = min(t[i][v << 1].odd, t[i][v << 1 | 1].even) + min(t[i][v << 1].even, t[i][v << 1 | 1].odd);
        t[i][v].odd = min(t[i][v << 1].odd, t[i][v << 1 | 1].odd) + min(t[i][v << 1].even, t[i][v << 1 | 1].even);
    }
}
void upd(int v, int tl, int tr, int id, int val) {
    if (tl == tr) {
        for (int i = 0; i < 30; ++i) {
            t[i][v].odd = val >> i & 1;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    if (id <= tm) {
        upd(v << 1, tl, tm, id, val);
    }
    else {
        upd(v << 1 | 1, tm + 1, tr, id, val);
    }
    for (int i = 0; i < 30; ++i) {
        t[i][v].odd = min(t[i][v << 1].odd, t[i][v << 1 | 1].even) + min(t[i][v << 1].even, t[i][v << 1 | 1].odd);
        t[i][v].odd = min(t[i][v << 1].odd, t[i][v << 1 | 1].odd) + min(t[i][v << 1].even, t[i][v << 1 | 1].even);
    }
}
vector<node> get(int v, int tl, int tr, int l, int r) {
    if (l > tr || tl > r) {
        vector<node> answer(30, {INT_MAX, INT_MAX});
        return answer;
    }
    if (l <= tl && tr <= r) {
        vector<node> answer;
        for (int i = 0; i < 30; ++i) {
            answer.push_back(t[i][v]);
        }
        return answer;
    }
    int tm = (tl + tr) >> 1;
    vector<node> lf = get(v << 1, tl, tm, l, r);
    vector<node> rg = get(v << 1 | 1, tm + 1, tr, l, r);
    vector<node> answer;
    for (int i = 0; i < 30; ++i) {
        answer.push_back(
            {
                min(lf[i].odd, rg[i].even) + min(lf[i].even, rg[i].odd), 
                min(lf[i].odd, rg[i].odd) + min(lf[i].even, rg[i].even)
            }
        );
    }
    return answer;
}
int solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    vector<node> answer = get(1, 0, n - 1, 0, 0);
    for (node j : answer) {
        cout << j.odd << ' ' << j.even << endl;
    }
    cout << endl;
    answer = get(1, 0, n - 1, 1, 1);
    for (node j : answer) {
        cout << j.odd << ' ' << j.even << endl;
    }
    cout << endl;
    answer = get(1, 0, n - 1, 2, 2);
    for (node j : answer) {
        cout << j.odd << ' ' << j.even << endl;
    }
    cout << endl;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            upd(1, 0, n - 1, y - 1, z);
        }
        else {
            vector<node> answer = get(1, 0, n - 1, y - 1, z - 1);
            // for (node j : answer) {
            //     cout << j.odd << ' ' << j.even << endl;
            // }
            // cout << endl;
        }
    }
    return 0;
}
int main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    solve();
    return 0;
}
// x ^ y => 1
// x ^ y => 0
// 1 1 1
