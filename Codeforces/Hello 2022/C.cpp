#include <bits/stdc++.h>

using namespace std;
// p1 = x 

// 1 
// q1 -> 1
// q1 -> x => p1 = x 

const int N = 1e6 + 100;
const int MOD = 1e9 + 7;

int Add(int &a, int b) { a += b; a -= a >= MOD ? MOD : 0; return a; }
int Mul(int a, int b) { return 1ll * a * b % MOD; }

int n, res[N], f[N];

int Ask(int u) {
    cout << "? " << u << endl;
    int x;
    cin >> x;
    return x;
}

void Answer() {
    cout << "!";
    for (int i = 1; i <= n; ++i) cout << ' ' << res[i];
    cout << endl;
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) f[i] = res[i] = 0;
    for (int i = 1; i <= n; ++i) if (f[i] == 0) {
        int x = Ask(i);
        vector<int> v; v.push_back(x);
        f[x] = 1;
        int y = x;
        do {
            y = Ask(i);
            v.push_back(y);
            f[y] = 1;
        } while (y != x);
        for (int j = 1; j < v.size(); ++j) {
            res[v[j - 1]] = v[j]; 
        }
    }
    Answer();
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--) Solve();
}