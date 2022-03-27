#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < piles[i].size(); j++) {
                piles[i][j] += piles[i][j - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                for (int t = 1; t <= piles[i - 1].size() && t <= j; t++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - t] + piles[i - 1][t - 1]);
                }
            }
        }
        return dp[n][k];
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

