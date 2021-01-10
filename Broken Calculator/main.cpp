#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

map<pair<int, int>, int> dp;
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = solve(X, Y);
        return res;
    }
    int solve(int x, int y) {
        pair<int, int> t = {x, y};
        if (dp.find(t) != dp.end()) return dp[t];
        if (y <= x) {
            return dp[t] = x - y;
        }
        int res = 1e9;
        if (y % 2 == 0) {
            res = min(res, 1 + solve(x, y / 2));
        } else {
            res = min(res, 1 + solve(x, y + 1));
        }
        return dp[t] = res;
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

