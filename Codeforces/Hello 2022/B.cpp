#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;
const int MOD = 1e9 + 7;

int Add(int &a, int b) { a += b; a -= a >= MOD ? MOD : 0; return a; }
int Mul(int a, int b) { return 1ll * a * b % MOD; }

void Solve() {
    int n;
    cin >> n;
    int ans = 2e9 + 100;
    pair<int, int> LMIN = {1e9 + 100, -1}, RMIN = {1e9 + 100, -1};
    for (int i = 1; i <= n; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        int cur = 2e9;
        if (i == 1 || (l == min(l, LMIN.first) && r == max(-RMIN.first, r)))
            cur = c;

        if (i == 1 || (LMIN.first == min(l, LMIN.first) && -RMIN.first == max(-RMIN.first, r)))
            cur = min(cur, ans);

        if (make_pair(l, c) < LMIN) {
            LMIN = {l, c};
        }
        if (make_pair(-r, c) < RMIN) {
            RMIN = {-r, c};
        }
        // cerr << LMIN.first << ' ' << LMIN.second << ' ' << RMIN.first << ' ' << RMIN.second << '\n';
        
        ans = min(cur, LMIN.second + RMIN.second);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--) Solve();
}