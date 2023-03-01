#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto [d, i, j] = pq.top(); pq.pop();
            if (i == n - 1 && j == m - 1) return d;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int nd = max(d + 1, grid[ni][nj]);
                    nd += (nd - ni - nj) % 2;
                    if (nd < dis[ni][nj]) {
                        dis[ni][nj] = nd;
                        pq.emplace(nd, ni, nj);
                    }
                }
            }
        }
        return -1;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    (void)!freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

