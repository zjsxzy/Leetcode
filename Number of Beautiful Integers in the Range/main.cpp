#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> num;
    int n, K;
    int dp[10][10][10][20][2][2];

    int numberOfBeautifulIntegers(int low, int high, int k) {
        K = k;
        return calc(high) - calc(low - 1);
    }

    int calc(int x) {
        memset(dp, -1, sizeof(dp));
        num.clear();
        while (x) {
            num.push_back(x % 10);
            x /= 10;
        }
        n = num.size();
        reverse(num.begin(), num.end());
        int res = dfs(0, 0, 0, 0, true, true);
        return res;
    }

    int dfs(int pos, int even, int odd, int modk, bool limit, bool lead) {
        if (pos == n) {
            if (!lead && even == odd && modk == 0) return 1;
            else return 0;
        }
        if (dp[pos][even][odd][modk][limit][lead] != -1) return dp[pos][even][odd][modk][limit][lead];
        int res = 0;
        for (int v = 0; v <= (limit ? num[pos] : 9); v++) {
            if (lead && v == 0) {
                res += dfs(pos + 1, even, odd, modk, limit && (v == num[pos]), true);
            } else {
                if (v & 1) {
                    res += dfs(pos + 1, even, odd + 1, (modk * 10 + v) % K, limit && (v == num[pos]), false);
                } else {
                    res += dfs(pos + 1, even + 1, odd, (modk * 10 + v) % K, limit && (v == num[pos]), false);
                }
            }
        }
        return dp[pos][even][odd][modk][limit][lead] = res;
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

