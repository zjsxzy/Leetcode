#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int inf = 1e9;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, inf));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int d = p.first;
            int x = p.second.first;
            int y = p.second.second;
            if (d > dist[x][y]) continue;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nd = d + grid[nx][ny];
                    if (nd < dist[nx][ny]) {
                        dist[nx][ny] = nd;
                        pq.push({nd, {nx, ny}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
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

