#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, (int)1e9));
        for (int j = 0; j < m; j++) {
            dp[0][j] = grid[0][j];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                int curr = grid[i][j];
                for (int k = 0; k < m; k++) {
                    dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + moveCost[curr][k] + grid[i + 1][k]);
                }
            }
        }
        int res = 1e9;
        for (int j = 0; j < m; j++) {
            res = min(res, dp[n - 1][j]);
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

