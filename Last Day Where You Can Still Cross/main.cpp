#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 0, hi = cells.size(), res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid, row, col, cells)) {
                lo = mid + 1;
                res = mid;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }

    bool check(int limit, int row, int col, vector<vector<int>>& cells) {
        vector<vector<bool>> vst(row, vector<bool>(col));
        vector<vector<bool>> water(row, vector<bool>(col));
        for (int i = 0; i < limit; i++) {
            water[cells[i][0] - 1][cells[i][1] - 1] = true;
        }
        queue<pair<int, int>> que;
        for (int j = 0; j < col; j++) {
            if (!water[0][j]) {
                que.push({0, j});
            }
        }
        while (!que.empty()) {
            auto p = que.front(); que.pop();
            vst[p.first][p.second] = true;
            for (int k = 0; k < 4; k++) {
                int x = p.first + dx[k], y = p.second + dy[k];
                if (inside(x, y, row, col) && !water[x][y] && !vst[x][y]) {
                    vst[x][y] = true;
                    que.push({x, y});
                }
            }
        }
        for (int j = 0; j < col; j++) {
            if (!water[row - 1][j] && vst[row - 1][j]) return true;
        }
        return false;
    }

    bool inside(int x, int y, int row, int col) {
        return x >= 0 && x < row && y >= 0 && y < col;
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

