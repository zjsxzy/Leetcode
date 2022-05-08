#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


添加备注


const int mod = 1000000007;
class Solution {
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        pressedKeys = "#" + pressedKeys;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            if (dp[i] == 0) continue;
            for (int j = 1; j <= 4; j++) {
                if (i + j > n) continue;
                if (j == 1) {
                    dp[i + j] += dp[i];
                    dp[i + j] %= mod;
                } else {
                    char c = pressedKeys[i + 1];
                    bool flag = true;
                    for (int k = i + 1; k <= i + j; k++) {
                        if (pressedKeys[k] != c) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        if (j <= 3 || (j == 4 && (c == '7' || c == '9'))) {
                            dp[i + j] += dp[i];
                            dp[i + j] %= mod;
                        }
                    }
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
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

