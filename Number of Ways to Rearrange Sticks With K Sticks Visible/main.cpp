#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;


const int MAXN = 1005;
const int mod = 1e9 + 7;
long long dp[MAXN][MAXN];

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j - 1] + (i - 1) * dp[i - 1][j];
                dp[i][j] %= mod;
            }
        }
        return (int)dp[n][k];
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    return 0;
}

