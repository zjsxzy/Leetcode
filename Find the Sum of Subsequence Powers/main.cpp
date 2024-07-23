#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        const int mod = 1e9 + 7;

        unordered_map<long long, int> dp;
        auto dfs = [&](auto&& dfs, int i, int j, int rest, int mi) -> int {
            if (rest == 0) return mi;
            if (rest > n - i) return 0;

            long long key = (1LL * mi) << 18 | (i << 12) | (j << 6) | rest;
            if (dp.contains(key)) return dp[key];
            long long ans = dfs(dfs, i + 1, j, rest, mi); // 不选nums[i];
            if (j == n) ans += dfs(dfs, i + 1, i, rest - 1, mi); // 选i且i是第一个
            else ans += dfs(dfs, i + 1, i, rest - 1, min(mi, nums[i] - nums[j])); // 选i且i不是第一个
            ans %= mod;
            dp[key] = ans;
            return dp[key];
        };

        return dfs(dfs, 0, n, k, INT_MAX);
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
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

