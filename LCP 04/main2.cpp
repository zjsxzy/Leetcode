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

const int MAXN = 64;
int mk[MAXN], cx[MAXN], cy[MAXN];
vector<int> adj[MAXN];

void addEdge(int u, int v) {
	adj[u].push_back(v);
}

int path(int u) {
	for (int i = 0, v; i < adj[u].size(); i++) {
		if (!mk[v = adj[u][i]]) {
			mk[v] = 1;
			if (cy[v] == -1 || path(cy[v])) {
				cx[u] = v;
				cy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

int MaxMatch(int n) {
	memset(cx, -1, sizeof(cx));
	memset(cy, -1, sizeof(cy));
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (cx[i] == -1) {
			memset(mk, 0, sizeof(mk));
			ret += path(i);
		}
	}
	return ret;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

class Solution {
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        vector<vector<bool> > mat(n, vector<bool>(m, false));
        for (auto x : broken) {
            mat[x[0]][x[1]] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!mat[i][j]) {
                    if ((i + j) & 1) { // odd cell
                        for (int k = 0; k < 4; k++) {
                            int x = i + dx[k], y = j + dy[k];
                            if (x >= 0 && x < n && y >= 0 && y < m && !mat[x][y]) {
                                int u = i * m + j, v = x * m + y;
                                addEdge(u, v);
                            }
                        }
                    }
                }
            }
        }

        int res = MaxMatch(n * m);
        return res;
    }
};

int main() {
}

