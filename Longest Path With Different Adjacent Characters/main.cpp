#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    string str;
    int res;
    vector<vector<int>> adj;
    vector<int> dp;
    int longestPath(vector<int>& parent, string s) {
        str = s;
        int n = s.size();
        adj.resize(n);
        dp.resize(n);
        for (int i = 0; i < n; i++) adj[i].clear(), dp[i] = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) continue;
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        res = 0;
        dfs(0, -1);
        return res;
    }
    void dfs(int u, int p) {
        int mx1 = 0, mx2 = 0;
        for (auto v: adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            if (str[u] != str[v]) {
                if (dp[v] > mx1) {
                    mx2 = mx1;
                    mx1 = dp[v];
                } else if (dp[v] > mx2) {
                    mx2 = dp[v];
                }
            }
        }
        dp[u] = mx1 + 1;
        res = max(res, mx1 + mx2 + 1);
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

