#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1e9));
        for (int i = 0; i < n; i++) dp[i][0] = 0;
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j] > grid[i][j - 1]) dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                if (i > 0 && grid[i][j] > grid[i - 1][j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                if (i < n - 1 && grid[i][j] > grid[i + 1][j - 1]) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, dp[i][j]);
            }
        }
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

