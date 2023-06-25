#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dp[1 << 15][15];
class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        const int mod = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = 1;
        }
        for (int s = 1; s < (1 << n); s++) {
            for (int j = 0; j < n; j++) {
                if (s >> j & 1 && dp[s][j]) {
                    for (int k = 0; k < n; k++) {
                        if (!(s >> k & 1) && (nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0)) {
                            dp[s | (1 << k)][k] += dp[s][j];
                            dp[s | (1 << k)][k] %= mod;
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += dp[(1 << n) - 1][i];
            res %= mod;
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

