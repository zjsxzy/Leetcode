#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        auto check = [&](int limit) {
            vector<int> dp(n + 1);
            dp[1] = (nums[0] <= limit);
            for (int i = 2; i <= n; i++) {
                int x = nums[i - 1];
                dp[i] = dp[i - 1];
                if (x <= limit) dp[i] = max(dp[i], dp[i - 2] + 1);
            }
            return dp[n] >= k;
        };
        int lo = 1, hi = 1e9, res;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid)) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
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

