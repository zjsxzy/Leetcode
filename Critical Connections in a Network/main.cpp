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

struct edge {
	int to, id;
};
class Solution {
public:
	vector<int> dfn, low, tag;
	vector<bool> vis;
	vector<vector<edge>> adj;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		dfn.clear(); low.clear(); vis.clear(); tag.clear();
		for (int i = 0; i < adj.size(); i++) {
			adj[i].clear();
		}
		dfn.resize(n); low.resize(n); adj.resize(n);
		vis.resize(connections.size()); tag.resize(connections.size());

		int i = 0;
		for (auto e : connections) {
			adj[e[0]].push_back({e[1], i});
			adj[e[1]].push_back({e[0], i});
			i++;
		}

		for (int i = 0; i < n; i++) {
			dfn[i] = -1;
			vis[i] = false;
		}
		for (int i = 0; i < n; i++) {
			if (dfn[i] == -1) {
				Tarjan(i, 0);
			}
		}
		vector<vector<int>> res;
		for (int i = 0; i < connections.size(); i++) {
			if (tag[i]) {
				res.push_back(connections[i]);
			}
		}
		return res;
    }

	void Tarjan(int u, int dep) {
		dfn[u] = low[u] = dep;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].to;
			int id = adj[u][i].id;
			if (dfn[v] == -1) {
				vis[id] = true;
				Tarjan(v, dep + 1);
				low[u] = min(low[u], low[v]);
				if (low[v] > dfn[u]) tag[id] = 1;
			} else if (!vis[id]) {
				low[u] = min(low[u], dfn[v]);
			}
		}
	}
};

int main() {
}

