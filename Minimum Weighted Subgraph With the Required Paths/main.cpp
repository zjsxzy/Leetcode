#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

struct edge {
    int to;
    long long cost;
    edge(int to, long long cost) {
        this->to = to;
        this->cost = cost;
    }
};
const long long inf = 1e18;
class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<edge>> adj(n), radj(n);
        for (int i = 0; i < n; i++) adj[i].clear(), radj[i].clear();
        for (auto e: edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            radj[e[1]].emplace_back(e[0], e[2]);
        }
        vector<long long> d1 = dijkstra(adj, src1);
        vector<long long> d2 = dijkstra(adj, src2);
        vector<long long> rd = dijkstra(radj, dest);
        long long res = inf;
        for (int i = 0; i < n; i++) {
            long long t = d1[i] + d2[i] + rd[i];
            if (t < res) res = t;
        }
        if (res >= inf) return -1;
        return res;
    }

    vector<long long> dijkstra(vector<vector<edge>>& adj, int st) {
        // construct graph: adj[u].push_back({v, c})
        vector<long long> dist(adj.size(), inf);
        dist[st] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, st});
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int v = p.second;
            if (p.first > dist[v]) continue;
            for (edge e : adj[v]) {
                long long nd = p.first + e.cost;
                if (nd < dist[e.to]) {
                    dist[e.to] = nd;
                    pq.push({nd, e.to});
                }
            }
        }
        return dist;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

