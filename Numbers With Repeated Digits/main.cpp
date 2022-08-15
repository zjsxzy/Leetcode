#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> digits;
    vector<vector<int>> dp;

    int dfs(int i, int mask, bool is_limit, bool is_num) {
        if (i == (int)digits.size()) return is_num;
        if (!is_limit && is_num && dp[i][mask] >= 0) return dp[i][mask];
        int res = 0;
        if (!is_num) res = dfs(i + 1, mask, false, false); // 跳过当前数位
        for (int d = 1 - is_num, up = is_limit ? digits[i] : 9; d <= up; d++) {
            if ((mask >> d & 1) == 0) {
                res += dfs(i + 1, mask | (1 << d), is_limit && d == up, true);
            }
        }
        if (!is_limit &&is_num) dp[i][mask] = res;
        return res;
    }

    int numDupDigitsAtMostN(int n) {
        digits.clear();
        int x = n;
        while (x) {
            digits.push_back(x % 10);
            x /= 10;
        }
        reverse(digits.begin(), digits.end());

        dp.assign((int)digits.size(), vector<int>(1 << 10, -1));
        return n - dfs(0, 0, true, false);
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
   (void)!freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

