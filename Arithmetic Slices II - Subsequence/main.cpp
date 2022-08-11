#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = 1ll * nums[i] - nums[j];
                auto it = dp[j].find(diff);
                int cnt = it == dp[j].end() ? 0 : it->second;
                res += cnt;
                dp[i][diff] += cnt + 1;
            }
        }
        return res;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

