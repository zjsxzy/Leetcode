#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int j = 0; j < m; j++) {
            int mx = 0;
            for (int i = 0; i < n; i++) {
                int p = 0;
                for (int k = 0; k < m; k++) {
                    if (grid[i][k] > grid[i][p]) {
                        p = k;
                    }
                }
                mx = max(mx, grid[i][p]);
                grid[i][p] = 0;
            }
            res += mx;
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
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

