#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct union_find{
    int N;
    vector<int> par, siz;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        for(int i=0; i<N; i++) par[i] = i;
    }
    int root(int X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y){
        return root(X) == root(Y);
    }
    void unite(int X, int Y){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return 0;
        const int inf = 1e9;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        vector<vector<int>> d(n, vector<int>(n, inf));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    d[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && d[x][y] + 1 < d[nx][ny]) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        auto id = [&](int i, int j) {
            return i * n + j;
        };
        auto check = [&](int limit) {
            union_find dsu(n * n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (d[i][j] < limit) continue;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && d[ni][nj] >= limit) {
                            dsu.unite(id(i, j), id(ni, nj));
                        }
                    }
                }
            }
            return dsu.same(id(0, 0), id(n - 1, n - 1));
        };
        int lo = 0, hi = n * n, res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

