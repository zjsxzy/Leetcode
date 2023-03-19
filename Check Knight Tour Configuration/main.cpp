#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        int n = grid.size();
        vector<pair<int, int>> p(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p[grid[i][j]] = {i, j};
            }
        }
        for (int x = 1; x < n * n; x++) {
            int dx = p[x].first - p[x - 1].first;
            int dy = p[x].second - p[x - 1].second;
            if (abs(dx) == 2 && abs(dy) == 1) continue;
            if (abs(dx) == 1 && abs(dy) == 2) continue;
            return false;
        }
        return true;
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

