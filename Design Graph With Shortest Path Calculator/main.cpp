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

class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        for (auto e: edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
        }
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].emplace_back(edge[1], edge[2]);
    }

    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }

    int dijkstra(int st, int ed) {
        // vector<vector<edge> > adj(n);
        // construct graph: adj[u].emplace_back(v, c)
        const int inf = 1e9;
        vector<int> dist(adj.size(), inf);
        dist[st] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, st});
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int v = p.second;
            if (p.first > dist[v]) continue;
            for (edge e : adj[v]) {
                int nd = p.first + e.cost;
                if (nd < dist[e.to]) {
                    dist[e.to] = nd;
                    pq.push({nd, e.to});
                }
            }
        }
        return dist[ed] == inf ? -1 : dist[ed];
    }

    vector<vector<edge>> adj;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

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

