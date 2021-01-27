#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 1000;
struct DisJointSet{
	int rank[MAXN], parent[MAXN];

	void init(int n) {
		for (int i = 0; i < n; i++) {
			rank[i] = 0;
			parent[i] = i;
		}
	}

	int Find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int x, int y) {
		x = Find(x);
		y = Find(y);

		if (x == y) return;

		if (rank[x] >= rank[y]) {
			parent[y] = x;
			if (rank[x] == rank[y])
				rank[x]++;
		}
		else {
			parent[x] = y;
		}
	}

	int count(int n) {
		int ret = 0;
		for (int i = 0; i < n; i++)
			ret += Find(i) == i;
		return ret;
	}
}uf;

int n;
int dfn[MAXN], low[MAXN], tag[MAXN];
vector<pair<int, int>> graph[MAXN];
bool visited[MAXN * 4];

void Tarjan(int u, int dep) {
    dfn[u] = low[u] = dep;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        int id = graph[u][i].second;
        if (dfn[v] == -1) {
            visited[id] = true;//It's an undirected graph
            Tarjan(v, dep + 1);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) tag[u]++;//Vertex u is a Cut-Vertex
        } else if (!visited[id]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void FindCutVertex() {
	for (int i = 0; i < n; i++) {
		dfn[i] = -1;
        tag[i] = 0;
    }
	for (int i = 0; i < n; i++) {
		if (dfn[i] == -1) {
			Tarjan(i, 0);
			tag[i]--;//Vertex i is the root
		}
    }
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

class Solution {
    public:
    int minDays(vector<vector<int>>& grid) {
        int r = SZ(grid), c = SZ(grid[0]);
        map<pair<int, int>, int> idx;
        n = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    idx[{i, j}] = n;
                    n++;
                }
            }
        }
        uf.init(n);
        for (int u = 0; u < n; u++) {
            graph[u].clear();
        }
        int edge = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    int u = idx[{i, j}];
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == 1) {
                            int v = idx[{x, y}];
                            uf.Union(u, v);
                            graph[u].push_back({v, edge});
                            graph[v].push_back({u, edge});
                            edge++;
                        }
                    }
                }
            }
        }
        for (int e = 0; e < edge; e++) {
            visited[e] = false;
        }
        int cnt = uf.count(n);
        if (cnt == 0 || cnt >= 2) return 0;
        FindCutVertex();
        for (int i = 0; i < n; i++) {
            if (tag[i]) {
                return 1;
            }
        }
        return 2;
    }
};

int main() {
    return 0;
}

