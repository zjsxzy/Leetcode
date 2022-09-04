#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
const int maxn = 3005;
const int base = 1000;
long long dp[maxn][maxn];
class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, 0, sizeof(dp));
        startPos += base;
        endPos += base;
        dp[0][startPos] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = startPos - base; j <= startPos + base; j++) {
                if (j + 1 <= startPos + base) {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= mod;
                }
                if (j - 1 >= startPos - base) {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= mod;
                }
            }
        }
        return dp[k][endPos];
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

