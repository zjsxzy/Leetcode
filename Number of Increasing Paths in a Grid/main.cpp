#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
class Solution {
public:
    int n, m;
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<int> deg(n * m);
        vector<vector<int>> g(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int u = idx(i, j);
                for (int d = 0; d < 4; d++) {
                    int x = i + dx[d], y = j + dy[d];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] > grid[i][j]) {
                        int v = idx(x, y);
                        g[u].push_back(v);
                        deg[v]++;
                    }
                }
            }
        }
        vector<int> dp(n * m, 1);
        queue<int> q;
        for (int i = 0; i < n * m; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        int res = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            // cout << u << ' ' << dp[u] << endl;
            res += dp[u];
            res %= mod;
            for (auto v: g[u]) {
                dp[v] += dp[u];
                dp[v] %= mod;
                deg[v]--;
                if (deg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return res;
    }

    int idx(int i, int j) {
        return i * m + j;
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

