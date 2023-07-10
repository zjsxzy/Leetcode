#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), res = 1;
        vector dp(n, vector(2, 1));
        for (int i = 1; i < n; i++) {
            if (nums1[i] >= nums1[i - 1]) {
                dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
            }
            if (nums1[i] >= nums2[i - 1]) {
                dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
            }
            if (nums2[i] >= nums1[i - 1]) {
                dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
            }
            if (nums2[i] >= nums2[i - 1]) {
                dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
            }
            res = max(res, dp[i][0]);
            res = max(res, dp[i][1]);
        }
        return res;
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

