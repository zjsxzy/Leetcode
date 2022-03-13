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
#include <cassert>
#include <climits>
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

const int MAXN = 105;
int vis[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

class Solution {
public:
    int n, m;
    vector<vector<int> > h;

    bool inside(pair<int, int> p) {
        return (p.first >= 0) && (p.first < n) && (p.second >= 0) && (p.second < m);
    }

    bool check(int diff) {
        queue<pair<int, int> > q;
        memset(vis, 0, sizeof(vis));
        q.push({0, 0});
        vis[0][0] = 1;
        while (!q.empty()) {
            pair<int, int> u = q.front(); q.pop();
            if (u.first == n - 1 && u.second == m - 1) return true;
            for (int k = 0; k < 4; k++) {
                pair<int, int> v;
                v.first = u.first + dx[k];
                v.second = u.second + dy[k];
                if (inside(v) && vis[v.first][v.second] ==0 && abs(h[v.first][v.second] - h[u.first][u.second]) <= diff) {
                    vis[v.first][v.second] = 1;
                    q.push(v);
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        if (n == 0) return 0;
        m = heights[0].size();
        if (m == 0) return 0;
        h = heights;
        int lo = 0, hi = 1000000;
        int res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid)) {
                res = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return res;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > h(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> h[i][j];
        }
    }
    Solution sol;
    cout << sol.minimumEffortPath(h) << endl;
    return 0;
}

