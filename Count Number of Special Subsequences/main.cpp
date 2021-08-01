#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int mod = 1e9 + 7;
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        vector<int> dp(3, 0);
        for (auto &x: nums) {
            if (x == 0) {
                dp[0] = (dp[0] * 2 + 1) % mod;
            } else if (x == 1) {
                dp[1] = (dp[1] * 2 % mod + dp[0]) % mod;
            } else if (x == 2) {
                dp[2] = (dp[2] * 2 % mod + dp[1]) % mod;
            }
        }
        return dp[2];
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

