#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dp[105][105][205];
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> val(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                val[i][j] = grid[i][j] == '(' ? 1 : -1;
            }
        }
        memset(dp, 0, sizeof(dp));
        if (val[0][0] == -1) return false;
        dp[0][0][1] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n + m; k++) {
                    if (dp[i][j][k]) {
                        if (i + 1 < n) {
                            int nk = k + val[i + 1][j];
                            if (nk >= 0 && nk < n + m) dp[i + 1][j][nk] = 1;
                        }
                        if (j + 1 < m) {
                            int nk = k + val[i][j + 1];
                            if (nk >= 0 && nk < n + m) dp[i][j + 1][nk] = 1;
                        }
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
    solve();
    return 0;
}

