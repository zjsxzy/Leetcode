#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector dp(n, vector(n, 0));
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                if (s[i] == s[j]) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
       solve();
    }
    return 0;
}

