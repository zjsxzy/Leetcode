#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), m = edges.size();
        vector<vector<int>> adj(n);
        vector<int> deg(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            deg[e[1]]++;
        }

        int res = -1, cnt = 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) q.push(i);
        }
        vector<vector<int>> dp(n, vector<int>(26));
        while (!q.empty()) {
            int u = q.front(); q.pop();
            dp[u][colors[u] - 'a']++;
            for (int k = 0; k < 26; k++) {
                res = max(res, dp[u][k]);
            }
            cnt++;
            for (auto &v : adj[u]) {
                for (int k = 0; k < 26; k++) {
                    dp[v][k] = max(dp[v][k], dp[u][k]);
                }
                deg[v]--;
                if (deg[v] == 0) q.push(v);
            }
        }
        if (cnt < n) return -1;
        return res;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

