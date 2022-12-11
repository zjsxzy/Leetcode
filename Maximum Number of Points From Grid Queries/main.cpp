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
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size(), q = queries.size();
        vector<pair<int, int>> que(q);
        for (int i = 0; i < q; i++) {
            que[i].first = queries[i];
            que[i].second = i;
        }
        sort(que.begin(), que.end());

        auto idx = [&](int i, int j) {
            return i * m + j;
        };
        vector<pair<int, int>> g(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[idx(i, j)].first = grid[i][j];
                g[idx(i, j)].second = idx(i, j);
            }
        }
        sort(g.begin(), g.end());

        union_find dsu(n * m);
        vector<int> ans(q);
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        int i = 0, j = 0;
        for (; i < q; i++) {
            if (que[i].first > grid[0][0]) {
                break;
            } else{
                ans[que[i].second] = 0;
            }
        }
        for (; i < q; i++) {
            while (j < n * m && g[j].first < que[i].first) {
                int x = g[j].second / m, y = g[j].second % m;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] < que[i].first) {
                        dsu.unite(g[j].second, idx(nx, ny));
                    }
                }
                j++;
            }
            ans[que[i].second] = dsu.siz[dsu.root(0)];
        }
        return ans;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

