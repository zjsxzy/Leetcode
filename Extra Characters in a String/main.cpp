#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            for (auto d: dictionary) {
                int m = d.size();
                if (i - m >= 0 && s.substr(i - m, m) == d) {
                    dp[i] = min(dp[i], dp[i - m]);
                }
            }
        }
        return dp[n];
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

