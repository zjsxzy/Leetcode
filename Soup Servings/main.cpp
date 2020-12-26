#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    double soupServings(int N) {
        N = (N / 25) + (N % 25 ? 1 : 0);
        if (N > 500) return 1.0;
        vector<vector<double>> dp(N + 1, vector<double>(N + 1));
        dp[N][N] = 1;
        int d[4][2] = {{4, 0}, {3, 1}, {2, 2}, {1, 3}};
        for (int i = N; i > 0; i--) {
            for (int j = N; j > 0; j--) {
                if (dp[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int _i = max(0, i - d[k][0]);
                    int _j = max(0, j - d[k][1]);
                    dp[_i][_j] += 0.25 * dp[i][j];
                }
            }
        }
        double res = dp[0][0] / 2;
        for (int i = 1; i <= N; i++) {
            res += dp[0][i];
        }
        return res;
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

