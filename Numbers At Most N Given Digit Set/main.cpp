#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> num;
    vector<string> digits;
    int dp[15][2][2];
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        this->digits = digits;
        num.clear();
        int x = n;
        while (x) {
            num.push_back(x % 10);
            x /= 10;
        }
        reverse(num.begin(), num.end());
        memset(dp, -1, sizeof(dp));
        return dfs(0, true, false);
    }

    int dfs(int i, bool is_limit, bool is_num) {
        if (i == (int)num.size()) return is_num;
        if (dp[i][is_limit][is_num] >= 0) return dp[i][is_limit][is_num];
        int res = 0;
        if (!is_num) res = dfs(i + 1, false, false); // 跳过当前数位
        int up = is_limit ? num[i] : 9;
        for (auto s: digits) {
            int d = s[0] - '0';
            if (d > up) break;
            res += dfs(i + 1, is_limit && d == up, true);
        }
        dp[i][is_limit][is_num] = res;
        return res;
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

