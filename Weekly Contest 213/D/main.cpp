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

const int MAXN = 33;
LL comb[MAXN][MAXN];

class Solution {
public:
    string res;

    void init() {
        int n = 30;
        memset(comb, 0, sizeof(comb));
        for (int i = 0; i <= n; i++) {
            comb[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            }
        }
    }

    void solve(int p, int k, int v, int h) {
        // cout << p << " " << res << endl;
        if (v + h == 0) return;
        if (v == 0) {
            for (int i = 0; i < h; i++) {
                res += "H";
            }
            return;
        }
        if (h == 0) {
            for (int i = 0; i < v; i++) {
                res += "V";
            }
            return;
        }
        if (k <= comb[v+h-1][h-1]) {
            res += "H";
            solve(p + 1, k, v, h - 1);
        } else {
            res += "V";
            solve(p + 1, k - comb[v+h-1][h-1], v - 1, h);
        }
    }

    string kthSmallestPath(vector<int>& destination, int k) {
        int row = destination[0], col = destination[1];
        init();
        res = "";
        solve(0, k, row, col);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> d;
    d.push_back(2); d.push_back(3);
    cout << sol.kthSmallestPath(d, 6) << endl;
    return 0;
}

