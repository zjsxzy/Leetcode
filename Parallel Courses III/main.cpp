#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 50005;
int deg[maxn], dp[maxn];
vector<int> adj[maxn];

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            deg[i] = 0;
            dp[i] = 0;
        }
        for (auto v: relations) {
            adj[v[0]].push_back(v[1]);
            deg[v[1]]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        int res = INT_MIN;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            dp[u] += time[u - 1];
            res = max(res, dp[u]);
            for (auto v: adj[u]) {
                dp[v] = max(dp[v], dp[u]);
                deg[v]--;
                if (deg[v] == 0) q.push(v);
            }
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
    solve();
    return 0;
}

