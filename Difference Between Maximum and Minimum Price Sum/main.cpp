#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> adj(n);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        long long res = 0;
        function<pair<long long, long long>(int, int)> dfs = [&](int u, int fa) -> pair<long long, long long> {
            long long p = price[u];
            long long max_s1 = 0, max_s2 = 0;
            bool leaf = true;
            for (auto v: adj[u]) {
                if (v == fa) continue;
                leaf = false;
                auto [s1, s2] = dfs(v, u);
                if (max_s1 == 0) res = max(res, s1);
                else res = max(res, max_s2 + p + s1);
                res = max(res, max_s1 + p + s2);
                max_s1 = max(max_s1, s1);
                max_s2 = max(max_s2, s2);
            }
            if (leaf) return {max_s1 + p, 0};
            else return {max_s1 + p, max_s2 + p};
        };
        dfs(0, -1);
        return res;
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

