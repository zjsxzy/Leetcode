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

const int inf = 1 << 30;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<int> f(m, 0);
        for (int j = 0; j < m; j++) {
            f[j] = arr[0][j];
        }
        for (int i = 1; i < n; i++) {
            int mn = inf, min_j, smn = inf;
            for (int j = 0; j < m; j++) {
                if (f[j] < mn) {
                    smn = mn;
                    mn = f[j];
                    min_j = j;
                } else if (f[j] < smn) {
                    smn = f[j];
                }
            }

            vector<int> g(m, inf);
            for (int j = 0; j < m; j++) {
                if (j != min_j) {
                    g[j] = min(g[j], mn + arr[i][j]);
                } else {
                    g[j] = min(g[j], smn + arr[i][j]);
                }
            }
            for (int j = 0; j < m; j++) {
                f[j] = g[j];
            }
        }
        int res = inf;
        for (int j = 0; j < m; j++) {
            res = min(res, f[j]);
        }
        return res;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    return 0;
}

