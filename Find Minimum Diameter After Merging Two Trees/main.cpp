#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = diameter(edges1), d2 = diameter(edges2);
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
    int diameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto& e: edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        auto bfs = [&](int s) {
            queue<int> q;
            vector<int> d(n, -1);
            d[s] = 0;
            q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                // cout << u << ' ' << d[u] << endl;
                for (auto& v: g[u]) {
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
                }
            }
            int v = 0;
            for (int i = 0; i < n; i++) {
                if (d[i] > d[v]) {
                    v = i;
                }
            }
            return make_pair(v, d[v]);
        };
        pair<int, int> ans = bfs(0);
        pair<int, int> res = bfs(ans.first);
        return res.second;
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

