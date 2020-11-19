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


class Solution {
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        vector<vector<bool> > mat(n, vector<bool>(m, false));
        for (auto x : broken) {
            mat[x[0]][x[1]] = true;
        }

        vector<int> f(1 << m, -1);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<int> g(1 << m, -1);
                for (int s = 0; s < (1 << m); s++) {
                    if (f[s] != -1) {
                        int up = (s & 1), left = (s & (1 << (m - 1)));

                        int new_state;
                        // broken cell
                        if (mat[i][j]) {
                            new_state = (s >> 1) | (1 << (m - 1));
                            if (g[new_state] == -1 || f[s] > g[new_state]) {
                                g[new_state] = f[s];
                            }
                            continue;
                        }

                        // put no one
                        new_state = (s >> 1);
                        if (g[new_state] == -1 || f[s] > g[new_state]) {
                            g[new_state] = f[s];
                        }

                        // put one horizontally
                        if (j > 0) {
                            if (!left) {
                                new_state = ((s >> 1) | (1 << (m - 1) | (1 << (m - 2))));
                                if (g[new_state] == -1 || f[s] + 1 > g[new_state]) {
                                    g[new_state] = f[s] + 1;
                                }
                            }
                        }

                        // put one vertically
                        if (i > 0) {
                            if (!up) {

                                new_state = ((s >> 1) | (1 << (m - 1))); // no need to | 1 because up cell will be deleted in next state
                                if (g[new_state] == -1 || f[s] + 1 > g[new_state]) {
                                    g[new_state] = f[s] + 1;
                                }
                            }
                        }
                    }
                }
                for (int s = 0; s < (1 << m); s++) {
                    f[s] = g[s];
                }
            }
        }
        int res = 0;
        for (int s = 0; s < (1 << m); s++) {
            res = max(res, f[s]);
        }
        return res;
    }
};

int main() {
}

