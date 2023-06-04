#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> num;
    int n, mins, maxs;
    const int mod = 1e9 + 7;
    int dp[25][225][2];

    int count(string num1, string num2, int min_sum, int max_sum) {
        mins = min_sum; maxs = max_sum;
        int r = calc(num2), l = calc(num1);
        int res = (r - l + mod) % mod;
        int sum = 0;
        for (auto c: num1) sum += c - '0';
        res += (sum >= min_sum && sum <= max_sum);
        return res % mod;
    }

    int calc(string x) {
        memset(dp, -1, sizeof(dp));
        num.clear();
        for (auto c: x) {
            num.push_back(c - '0');
        }
        n = num.size();
        int res = dfs(0, 0, true);
        return res;
    }

    int dfs(int pos, int sum, bool limit) {
        if (pos == n) return sum >= mins;
        if (dp[pos][sum][limit] != -1) return dp[pos][sum][limit];
        int res = 0;
        for (int v = 0; v <= (limit ? num[pos] : 9); v++) {
            if (sum + v > maxs) continue;
            res += dfs(pos + 1, sum + v, limit && (v == num[pos]));
            res %= mod;
        }
        dp[pos][sum][limit] = res;
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

