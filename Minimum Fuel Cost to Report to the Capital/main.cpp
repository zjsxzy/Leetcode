#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> sum;
    long long res, s;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        s = seats;
        int m = roads.size();
        int n = 0;
        for (auto e: roads) {
            n = max(n, e[0]);
            n = max(n, e[1]);
        }
        adj.resize(n + 1);
        sum.resize(n + 1);
        for (auto e: roads) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        res = 0;
        dfs(0, -1);
        return res;
    }
    void dfs(int u, int p) {
        sum[u] = 1;
        for (auto v: adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            res += (long long)(sum[v] + s - 1) / s;
            sum[u] += sum[v];
        }
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

