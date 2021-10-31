#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int dp[45][45][2005];
    bool possiblyEquals(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        s1 = " " + s1;
        s2 = " " + s2;
        int B = 1000;
        dp[0][0][B] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 1; k <= 2000; k++) {
                    if (!dp[i][j][k]) continue;
                    if (k == B && i < n && j < m && s1[i + 1] == s2[j + 1]) {
                        dp[i + 1][j + 1][B] = true;
                    }
                    if (k > B) {
                        if (i < n && s1[i + 1] >= 'a' && s1[i + 1] <= 'z') {
                            dp[i + 1][j][k - 1] = true;
                        }
                    }
                    if (k < B) {
                        if (j < m && s2[j + 1] >= 'a' && s2[j + 1] <= 'z') {
                            dp[i][j + 1][k + 1] = true;
                        }
                    }

                    int x = 0;
                    for (int u = i + 1; u <= n; u++) {
                        if (s1[u] < '0' || s1[u] > '9') break;
                        x = x * 10 + s1[u] - '0';
                        if (k - x > 0) dp[u][j][k - x] = true;
                    }
                    x = 0;
                    for (int v = j + 1; v <= m; v++) {
                        if (s2[v] < '0' || s2[v] > '9') break;
                        x = x * 10 + s2[v] - '0';
                        if (k + x <= 2000) dp[i][v][k + x] = true;
                    }
                }
            }
        }
        return dp[n][m][B];
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

