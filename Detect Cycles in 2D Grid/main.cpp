#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;


const int MAXN = 505;
bool vis[MAXN][MAXN];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

class Solution {
public:
    bool find;
    int n, m;
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(vis, false, sizeof(vis));
        find = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') continue;
                if (vis[i][j]) continue;
                dfs({i, j}, {-1, -1}, grid);
                if (find) return true;
            }
        }
        return false;
    }

    void dfs(pair<int, int> cur, pair<int, int> prev, vector<vector<char>>& grid) {
        int x = cur.first, y = cur.second;
        if (vis[x][y]) {
            find = true;
            return;
        }
        vis[x][y] = true;
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (prev.first == xx && prev.second == yy) continue;
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == grid[x][y]) {
                dfs({xx, yy}, {x, y}, grid);
            }
        }
    }
};

int main() {
}

