#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;
const int MOD = 1e9 + 7;

int Add(int &a, int b) { a += b; a -= a >= MOD ? MOD : 0; return a; }
int Mul(int a, int b) { return 1ll * a * b % MOD; }

void Solve() {
    int n, k;
    cin >> n >> k;
    if (k > (n + 1) / 2) {
        cout << -1 << '\n';
    } else {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) if (i == j && i % 2 == 0 && cnt < k) {
                cout << 'R';
                ++cnt;
            } else cout << '.';
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--) Solve();
}