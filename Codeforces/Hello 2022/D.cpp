#include <bits/stdc++.h>

using namespace std;

const int N = 1111;

int n, c[N][N];
long long d[N][N], sum[N][N];

int id(int u) {
    return u + n;
}

long long Sum(int x1, int y1, int x2, int y2) {
    x1 = id(x1); x2 = id(x2); y1 = id(y1); y2 = id(y2);
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int dd[4] = {1, -1, 0, 0};
int cc[4] = {0, 0, 1, -1};


bool inside(int i, int j) {
    return 0 <= i && i <= 2 * n && 0 <= j && j <= 2 * n;
}

void Solve() {
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) cin >> c[i][j];
    }
    for (int i = 0; i < 3 * n; ++i) {
        for (int j = 0; j < 3 * n; ++j) {
            d[i][j] = 1e18;
            int cur = c[(i + n) % (2 * n)][(j + n) % (2 * n)];
            sum[i + 1][j + 1] = cur + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
        }
    }
    priority_queue<pair<long long, pair<int, int> > > heap;
    d[n][n] = Sum(1, 1, n, n);
    heap.push({d[n][n], {n, n}});
    while (heap.size()) {
        long long dist = -heap.top().first;
        pair<int, int> u = heap.top().second;
        int i = u.first, j = u.second;
        // cerr << i << ' ' << j << ' ' << dist << '\n';
        if ((i == 0 || i == 2 * n) && (j == 0 || j == 2 * n)) {
            cout << dist << '\n';
            return;
        }
        heap.pop();
        if (dist > d[i][j]) continue;
        for (int k = 0; k < 4; ++k) {
            int ii = i + dd[k], jj = j + cc[k];
            long long cost = 0;
            // [i - n + 1, i][j - n + 1.. j]
            if (k == 0) {
                // ii = i + 1
                cost = Sum(i + 1, j - n + 1, i + 1, j);
            } else if (k == 1) {
                cost = Sum(i - n, j - n + 1, i - n, j);
            } else if (k == 2) {
                cost = Sum(i - n + 1, j + 1, i, j + 1);
            } else cost = Sum(i - n + 1, j - n, i - n + 1, j - n);

            if (inside(ii, jj) && d[ii][jj] > dist + cost) {
                // cerr << i + n << ' ' << j + n << ' ' << ii + n << ' ' << jj + n << ' ' << cost << '\n';
                d[ii][jj] = dist + cost;
                heap.push({-d[ii][jj], {ii, jj}});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--) Solve();
}