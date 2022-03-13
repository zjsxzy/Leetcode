#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int dp[MAXN][MAXN], sum[MAXN][MAXN];

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; i++){
            sum[i][i] = stones[i];
            for (int j = i + 1; j < n; j++) {
                sum[i][j] = sum[i][j - 1] + stones[j];
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int d = 1; d < n; d++) {
            for(int i = 0; i + d < n; i++){
                int j = i + d;
                int l = sum[i + 1][j] - dp[i + 1][j];
                int r = sum[i][j - 1] - dp[i][j - 1];
                dp[i][j] = max(l, r);
            }
        }
        return dp[0][n - 1];
    }
};