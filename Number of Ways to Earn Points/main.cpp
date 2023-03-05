#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<int> dp(target + 1);
        const int mod = 1e9 + 7;
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            int m = types[i][0], s = types[i][1];
            vector<int> newdp = dp;
            for (int j = 0; j <= target; j++) {
                if (!dp[j]) continue;
                for (int k = 1; k <= m; k++) {
                    if (j + k * s <= target) {
                        newdp[j + k * s] += dp[j];
                        newdp[j + k * s] %= mod;
                    }
                }
            }
            dp = newdp;
        }
        return dp[target];
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

