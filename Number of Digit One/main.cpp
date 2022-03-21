#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int dp[11][11][2];

class Solution {
public:
    vector<int> num;
    int sz;
    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        while (n) {
            num.push_back(n % 10);
            n /= 10;
        }
        sz = num.size();
        reverse(num.begin(), num.end());
        int res = dfs(0, 0, true);
        return res;
    }

    int dfs(int pos, int cnt, bool limit) {
        if (pos == sz) return cnt;
        if (dp[pos][cnt][limit] != -1) return dp[pos][cnt][limit];
        int res = 0;
        for (int v = 0; v <= (limit ? num[pos] : 9); v++) {
            res += dfs(pos + 1, cnt + (v == 1), limit && (v == num[pos]));
        }
        return dp[pos][cnt][limit] = res;
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

