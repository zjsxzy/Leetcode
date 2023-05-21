#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct edge {
    int to, cost;
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};

class Solution {
public:
    vector<vector<edge>> adj;
    vector<int> dist;

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        int m = edges.size();
        adj.assign(n, {});
        dist.assign(n, 1e9);
        dist[source] = 0;
        for (auto edg: edges) {
            if (edg[2] == -1) continue;
            adj[edg[0]].emplace_back(edg[1], edg[2]);
            adj[edg[1]].emplace_back(edg[0], edg[2]);
        }
        int res = dijkstra(source, destination);
        if (res < target) {
            return {};
        }
        if (res == target) {
            for (auto& edg: edges) {
                if (edg[2] == -1) edg[2] = 1e9;
            }
            return edges;
        }
        bool flag = false;
        for (auto& edg: edges) {
            int u = edg[0], v = edg[1], w = edg[2];
            if (w > 0) continue;
            if (flag) {
                edg[2] = 2e9;
                continue;
            }
            edg[2] = 1;
            adj[u].emplace_back(v, 1);
            adj[v].emplace_back(u, 1);
            int res = dijkstra(source, destination);
            if (res <= target) {
                flag = true;
                w = target - res + 1;
                edg[2] = w;
            }
        }
        if (!flag) return {};
        return edges;
    }

    int dijkstra(int st, int ed) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, st});
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int v = p.second;
            if (p.first > dist[v]) continue;
            for (edge e : adj[v]) {
                int nd = p.first + e.cost;
                if (nd <= dist[e.to]) {
                    dist[e.to] = nd;
                    pq.push({nd, e.to});
                }
            }
        }
        return dist[ed];
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
       solve();
    }
    return 0;
}

