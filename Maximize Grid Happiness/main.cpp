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

const int inf = 1e9;
class Solution {
public:
    int f[729][7][7], g[729][7][7];
    int pw[6];
    int happiness(int x, int y) {
        if (x == 0 || y == 0) {
            return 0;
        } else if (x == 1 && y == 1) {
            return -30 + -30;
        } else if (x == 2 && y == 2) {
            return 20 + 20;
        } else {
            return -30 + 20;
        }
    }
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        pw[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw[i] = pw[i - 1] * 3;
        }
        int state = pw[n];
        for (int s = 0; s < state; s++)
            for (int x = 0; x <= introvertsCount; x++)
                for (int y = 0; y <= extrovertsCount; y++) {
                    f[s][x][y] = -inf;
                }

        f[0][0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 初始化
                for (int s = 0; s < state; s++) {
                    for (int x = 0; x <= introvertsCount; x++) {
                        for (int y = 0; y <= extrovertsCount; y++) {
                            g[s][x][y] = -inf;
                        }
                    }
                }

                for (int s = 0; s < state; s++) {
                    for (int x = 0; x <= introvertsCount; x++) {
                        for (int y = 0; y <= extrovertsCount; y++) {
                            if (f[s][x][y] >= 0) {
                                int up = s % 3; // cell up
                                int left = s / pw[n - 1]; // cell left
                                if (i == 0) up = 0; // no cell up if i == 0
                                if (j == 0) left = 0; // no cell left if j = 0

                                // put no one
                                int new_state = s / 3;
                                g[new_state][x][y] = max(g[new_state][x][y], f[s][x][y]);

                                // put one introverts
                                if (x != introvertsCount) {
                                    new_state = s / 3 + pw[n - 1] * 1;
                                    int value = 120 + happiness(1, up) + happiness(1, left);
                                    g[new_state][x + 1][y] = max(g[new_state][x + 1][y], f[s][x][y] + value);
                                }

                                // put one extroverts
                                if (y != extrovertsCount) {
                                    new_state = s / 3 + pw[n - 1] * 2;
                                    int value = 40 + happiness(2, up) + happiness(2, left);
                                    g[new_state][x][y + 1] = max(g[new_state][x][y + 1], f[s][x][y] + value);
                                }
                            }
                        }
                    }
                }

                // cout << i << " " << j << endl;
                for (int s = 0; s < state; s++) {
                    for (int x = 0; x <= introvertsCount; x++) {
                        for (int y = 0; y <= extrovertsCount; y++) {
                            // if (i == 1 && j == 0 && g[s][x][y] > 0)
                            //     cout << out(s) << " " << x << " " << y << " " << g[s][x][y] << endl;
                            f[s][x][y] = g[s][x][y];
                        }
                    }
                }
            }
        }

        int res = -inf;
        for (int s = 0; s < state; s++)
            for (int x = 0; x <= introvertsCount; x++)
                for (int y = 0; y <= extrovertsCount; y++) {
                    res = max(res, f[s][x][y]);
                }
        return res;

    }

    string out(int mask) {
        string res = "";
        while (mask) {
            res += char('0' + mask % 3);
            mask /= 3;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int m, n, in, ex;
    while (cin >> m >> n >> in >> ex) {
        cout << sol.getMaxGridHappiness(m, n, in, ex) << endl;
    }
    return 0;
}
