#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1e9);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (-target <= nums[i] - nums[j] && nums[i] - nums[j] <= target) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return max(-1, dp[n - 1]);
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    (void)!freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

