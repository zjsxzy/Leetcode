#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:

    int minimumMoves(vector<vector<int>>& grid) {
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        vector<int> fact(9, 1);
        for (int i = 1; i < 9; i++) fact[i] = fact[i - 1] * 10;
        map<int, int> d;
        queue<int> q;
        int s = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                s = s * 10 + grid[i][j];
            }
        }
        d[s] = 0;
        q.push(s);
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            if (u == 111111111) {
                return d[u];
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (u / fact[num2pos(i, j)] % 10 > 1) {
                        for (int k = 0; k < 4; k++) {
                            int ni = i + dx[k], nj = j + dy[k];
                            if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3) {
                                auto v = u;
                                v -= fact[num2pos(i, j)];
                                v += fact[num2pos(ni, nj)];
                                if (d.find(v) == d.end()) {
                                    d[v] = d[u] + 1;
                                    q.push(v);
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }

    int num2pos(int i, int j) {
        return i * 3 + j;
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

