#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) dp[0][0][grid[0][0] % k] = 1;
                if (i - 1 >= 0) {
                    for (int x = 0; x < k; x++) {
                        dp[i][j][(x + grid[i][j]) % k] += dp[i - 1][j][x];
                        dp[i][j][(x + grid[i][j]) % k] %= mod;
                    }
                }
                if (j - 1 >= 0) {
                    for (int x = 0; x < k; x++) {
                        dp[i][j][(x + grid[i][j]) % k] += dp[i][j - 1][x];
                        dp[i][j][(x + grid[i][j]) % k] %= mod;
                    }
                }
            }
        }
        return dp[n - 1][m - 1][0];
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

