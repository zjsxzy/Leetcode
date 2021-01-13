#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int inf = 1e9;
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> sum(1 << n);
        for (int s = 0; s < (1 << n); s++) {
            for (int i = 0; i < n; i++) {
                if ((s >> i) & 1) {
                    sum[s] += jobs[i];
                }
            }
        }
        vector<vector<int>> dp(k + 1, vector<int>(1 << n));
        for (int i = 0; i <= k; i++) {
            for (int s = 1; s < (1 << n); s++) {
                dp[i][s] = inf;
            }
        }
        for (int i = 1; i <= k; i++) {
            for (int s = 1; s < (1 << n); s++) {
                for (int t = s; t > 0; t = (t - 1) & s) {
                    dp[i][s] = min(dp[i][s], max(dp[i - 1][s ^ t], sum[t]));
                }
            }
        }
        return dp[k][(1 << n) - 1];
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

