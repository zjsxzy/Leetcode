#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int res = m + 1;
        for (int i = 0; i < m; i++) {
            int s = edges[i][0], t = edges[i][1];
            queue<int> q;
            vector<int> d(n, m + 1);
            d[s] = 0;
            for (auto v: g[s]) {
                if (v == t) continue;
                d[v] = d[s] + 1;
                q.push(v);
            }
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto v: g[u]) {
                    if (d[u] + 1 < d[v]) {
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
                }
            }
            if (d[t] < m + 1) {
                res = min(res, d[t] + 1);
            }
        }
        if (res == m + 1) return -1;
        return res;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

