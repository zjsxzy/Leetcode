#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, 2e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> cnt(n + 1);
            int t = 0;
            for (int j = i; j >= 1; j--) {
                cnt[nums[j - 1]]++;
                if (cnt[nums[j - 1]] == 2) t += 2;
                else if (cnt[nums[j - 1]] > 2) t++;
                dp[i] = min(dp[i], dp[j - 1] + k + t);
            }
        }
        return dp[n];
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

