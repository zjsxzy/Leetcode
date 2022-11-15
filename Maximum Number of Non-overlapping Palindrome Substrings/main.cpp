#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = 0; i < n; i++) f[i][i] = 1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) f[i][i + 1] = 1;
        }
        for (int l = 3; l <= n; l++) {
            for (int i = 0; i < n; i++) {
                int j = i + l - 1;
                if (j >= n) continue;
                if (f[i + 1][j - 1] && s[i] == s[j]) f[i][j] = 1;
            }
        }
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (int j = k; j <= i; j++) {
                if (f[i - j][i - 1]) dp[i] = max(dp[i], dp[i - j] + 1);
            }
        }
        return dp[n];
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

