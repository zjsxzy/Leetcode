#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
const int maxn = 1005;
long long dp[maxn][maxn];

// index from 0
struct Fenwick{
    using T = long long;
    vector<T> tree;
    int n;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void init(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, T val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
            tree[pos] %= mod;
        }
    }
    T get(int r) {
        T ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
            ans %= mod;
        }
        return ans % mod;
    }
};

class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        s = ' ' + s;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        if (!prime(s[1])) return 0;

        Fenwick tree(n + 1);
        tree.upd(0, 1);

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                if (prime(s[i])) continue;
                // for (int l = minLength; l <= i; l++) {
                //     if (prime(s[i - l + 1])) {
                //         dp[i][j] += dp[i - l][j - 1];
                //         dp[i][j] %= mod;
                //     }
                // }
                // cout << i << ' ' << j << ' ' << tree.get(i - minLength) << endl;
                dp[i][j] += tree.get(i - minLength);
                dp[i][j] %= mod;
            }
            // cout << j << endl;
            tree.init(n + 1);
            // tree.upd(0, 1);
            for (int i = 1; i <= n; i++) {
                if (prime(s[i])) {
                    // cout << i - 1 << ' ' << j << ' ' << dp[i - 1][j] << endl;
                    tree.upd(i - 1, dp[i - 1][j]);
                }

            }
        }
        return dp[n][k];
    }

    bool prime(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
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

