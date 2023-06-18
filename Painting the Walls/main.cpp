#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        const int inf = 1e9;
        int base = n;
        vector<int> dp(2 * n + 1, inf);
        dp[base] = 0;
        for (int i = 0; i < n; i++) {
            vector<int> ndp(2 * n + 1, inf);
            for (int j = -n; j <= n; j++) {
                if (dp[base + j] == inf) continue;
                // no pick
                if (j > -n) {
                    ndp[base + j - 1] = min(ndp[base + j - 1], dp[base + j]);
                }
                // pick
                ndp[base + min(n, j + time[i])] = min(ndp[base + min(n, j + time[i])], dp[base + j] + cost[i]);
            }
            dp = ndp;
        }
        int res = inf;
        for (int j = 0; j <= n; j++) res = min(res, dp[base + j]);
        return res;
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
       solve();
    }
    return 0;
}

