#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int maxn = 105;
vector<int> num;
int n;
int dp[maxn][15][2][2];

class Solution {
public:
    int countSteppingNumbers(string low, string high) {
        return (f(high) - f(low) + mod + check(low)) % mod;
    }

    bool check(string s) {
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (abs((s[i] - '0') - (s[i - 1] - '0')) != 1) return false;
        }
        return true;
    }

    int dfs(int pos, int last, bool limit, bool lead) {
        if (pos == n) return 1;
        if (dp[pos][last][limit][lead] != -1) return dp[pos][last][limit][lead];
        int res = 0;
        for (int v = 0; v <= (limit ? num[pos] : 9); v++) {
            if (last != 11 && abs(v - last) != 1) continue;
            if (lead && v == 0) {
                res += dfs(pos + 1, 11, limit && (v == num[pos]), true);
                res %= mod;
            } else {
                res += dfs(pos + 1, v, limit && (v == num[pos]), false);
                res %= mod;
            }
        }
        return dp[pos][last][limit][lead] = res;
    }

    int f(string s) {
        memset(dp, -1, sizeof(dp));
        n = s.size();
        num.clear();
        for (auto c: s) num.push_back(c - '0');
        int res = dfs(0, 11, true, true);
        return res;
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

