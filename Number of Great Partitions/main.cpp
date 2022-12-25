#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
const int maxn = 1005;
int dp[maxn][maxn];

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for (auto x: nums) sum += x;
        if (sum < k * 2) return 0;

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= mod;
                if (j + nums[i] < k) {
                    dp[i + 1][j + nums[i]] += dp[i][j];
                    dp[i + 1][j + nums[i]] %= mod;
                }
            }
        }

        int res = 1;
        for (int i = 0; i < n; i++) {
            res = res * 2 % mod;
        }
        for (int j = 0; j < k; j++) {
            res = (res - dp[n][j] + mod) % mod;
            res = (res - dp[n][j] + mod) % mod;
        }
        return res;
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

