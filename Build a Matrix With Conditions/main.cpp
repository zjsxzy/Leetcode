#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        int n = rowConditions.size(), m = colConditions.size();
        vector<vector<int>> adj(k + 1);
        vector<int> deg(k + 1);
        for (auto r: rowConditions) {
            adj[r[0]].push_back(r[1]);
            deg[r[1]]++;
        }
        vector<int> topo = topo_sort(adj, deg);
        vector<vector<int>> empty;
        if (topo.size() != k) return empty;
        vector<int> row(k + 1);
        for (int i = 0; i < k; i++) {
            row[topo[i]] = i;
        }

        adj.assign(k + 1, {});
        deg.assign(k + 1, 0);
        for (auto c: colConditions) {
            adj[c[0]].push_back(c[1]);
            deg[c[1]]++;
        }
        topo = topo_sort(adj, deg);
        if (topo.size() != k) return empty;
        vector<int> col(k + 1);
        for (int i = 0; i < k; i++) {
            col[topo[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k));
        for (int i = 1; i <= k; i++) {
            ans[row[i]][col[i]] = i;
        }
        return ans;
    }

    vector<int> topo_sort(vector<vector<int>>& adj, vector<int>& deg) {
        int n = adj.size();
        queue<int> q;
        for (int i = 1; i < n; i++) {
            if (deg[i] == 0) q.push(i);
        }
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (auto v: adj[u]) {
                deg[v]--;
                if (deg[v] == 0) q.push(v);
            }
        }
        return topo;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

