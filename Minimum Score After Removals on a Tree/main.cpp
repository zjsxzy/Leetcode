#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int m = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int res = INT_MAX;
        vector<int> f(n), s(2);
        function<void(int, int, int)> dfs = [&](int u, int p, int label) {
            for (auto v: adj[u]) {
                if (v == p) continue;
                dfs(v, u, label);
                if (label < 2) {
                    int a = f[v], b = s[label] ^ f[v], c = s[label ^ 1];
                    res = min(res, max({a, b, c}) - min({a, b, c}));
                }
                f[u] ^= f[v];
            }
            f[u] ^= nums[u];
        };
        for (int i = 0; i < m; i++) {
            f.assign(n, 0);
            dfs(edges[i][0], edges[i][1], 2);
            dfs(edges[i][1], edges[i][0], 2);
            s[0] = f[edges[i][0]]; s[1] = f[edges[i][1]];

            f.assign(n, 0);
            dfs(edges[i][0], edges[i][1], 0);
            dfs(edges[i][1], edges[i][0], 1);
        }
        return res;
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

