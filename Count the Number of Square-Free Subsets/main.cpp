#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;

class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int m = primes.size();
        vector<int> dp(1 << m);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {

            vector<int> next_dp = dp;
            int x = nums[i];

            bool flag = true;
            for (int k = 1; k < m; k++) {
                if (x % (primes[k] * primes[k]) == 0) {
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;

            for (int j = 0; j < (1 << m); j++) {
                flag = true;
                for (int k = 1; k < m; k++) {
                    if (x % primes[k] == 0 && (j >> k & 1)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    int nj = j;
                    for (int j = 0; j < m; j++) {
                        if (x % primes[j] == 0) nj |= (1 << j);
                    }
                    next_dp[nj] += dp[j];
                    next_dp[nj] %= mod;
                }
            }

            dp = next_dp;

        }

        int res = 0;
        for (int j = 1; j < (1 << m); j++) {
            res += dp[j];
            res %= mod;
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

