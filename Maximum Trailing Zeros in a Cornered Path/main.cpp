#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> cnt2(n, vector<int>(m)), cnt5(n, vector<int>(m));
        vector<vector<int>> left2(n, vector<int>(m)), up2(n, vector<int>(m));
        vector<vector<int>> left5(n, vector<int>(m)), up5(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = grid[i][j];
                int c2 = 0, c5 = 0;
                while (x % 2 == 0) {
                    c2++;
                    x /= 2;
                }
                while (x % 5 == 0) {
                    c5++;
                    x /= 5;
                }
                cnt2[i][j] = c2;
                cnt5[i][j] = c5;

                if (j == 0) {
                    left2[i][j] = c2;
                    left5[i][j] = c5;
                } else {
                    left2[i][j] = left2[i][j - 1] + c2;
                    left5[i][j] = left5[i][j - 1] + c5;
                }
                if (i == 0) {
                    up2[i][j] = c2;
                    up5[i][j] = c5;
                } else {
                    up2[i][j] = up2[i - 1][j] + c2;
                    up5[i][j] = up5[i - 1][j] + c5;
                }
            }
        }
        vector<vector<int>> right2(n, vector<int>(m)), down2(n, vector<int>(m));
        vector<vector<int>> right5(n, vector<int>(m)), down5(n, vector<int>(m));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (j == m - 1) {
                    right2[i][j] = cnt2[i][j];
                    right5[i][j] = cnt5[i][j];
                } else {
                    right2[i][j] = right2[i][j + 1] + cnt2[i][j];
                    right5[i][j] = right5[i][j + 1] + cnt5[i][j];
                }
                if (i == n - 1) {
                    down2[i][j] = cnt2[i][j];
                    down5[i][j] = cnt5[i][j];
                } else {
                    down2[i][j] = down2[i + 1][j] + cnt2[i][j];
                    down5[i][j] = down5[i + 1][j] + cnt5[i][j];
                }
            }
        }



        if (n == 1) {
            return min(right2[0][0], right5[0][0]);
        }
        if (m == 1) {
            return min(down2[0][0], down5[0][0]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int c2 = left2[i][j] + up2[i][j] - cnt2[i][j];
                int c5 = left5[i][j] + up5[i][j] - cnt5[i][j];
                res = max(res, min(c2, c5));

                c2 = left2[i][j] + down2[i][j] - cnt2[i][j];
                c5 = left5[i][j] + down5[i][j] - cnt5[i][j];
                res = max(res, min(c2, c5));

                c2 = right2[i][j] + up2[i][j] - cnt2[i][j];
                c5 = right5[i][j] + up5[i][j] - cnt5[i][j];
                res = max(res, min(c2, c5));

                c2 = right2[i][j] + down2[i][j] - cnt2[i][j];
                c5 = right5[i][j] + down5[i][j] - cnt5[i][j];
                res = max(res, min(c2, c5));
            }
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

