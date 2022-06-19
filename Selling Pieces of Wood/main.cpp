#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long p[205][205], dp[205][205];
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        memset(p, 0, sizeof(p));
        memset(dp, -1, sizeof(dp));
        for (auto& x: prices) {
            p[x[0]][x[1]] = x[2];
        }
        return dfs(m, n);
    }

    long long dfs(int n, int m) {
        if (dp[n][m] != -1) return dp[n][m];
        long long res = p[n][m];
        for (int i = 1; i < n; i++) {
            res = max(res, dfs(i, m) + dfs(n - i, m));
        }
        for (int j = 1; j < m;j ++) {
            res = max(res, dfs(n, j) + dfs(n, m - j));
        }
        return dp[n][m] = res;
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

