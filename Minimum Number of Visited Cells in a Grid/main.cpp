#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (n == 1 && m == 1) return 1;

        vector<set<int>> row(n), col(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i].insert(j);
                col[j].insert(i);
            }
        }
        row[0].erase(0); col[0].erase(0);

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({1, {0, 0}});

        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int d = p.first, i = p.second.first, j = p.second.second;
            if (d > dist[i][j]) continue;
            dist[i][j] = d;
            int k = grid[i][j];

            while (true) {
                auto x = col[j].lower_bound(i + 1);
                if (x == col[j].end()) break;
                if (*x > i + k) break;
                pq.push({d + 1, {*x, j}});
                col[j].erase(x);
            }
            while (true) {
                auto y = row[i].lower_bound(j + 1);
                if (y == row[i].end()) break;
                if (*y > j + k) break;
                pq.push({d + 1, {i, *y}});
                row[i].erase(y);
            }

        }

        return dist[n - 1][m - 1] == 1e9 ? -1 : dist[n - 1][m - 1];
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

