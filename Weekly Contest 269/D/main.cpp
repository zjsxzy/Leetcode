#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;


class Solution {
public:
    map<int, map<int, vector<int>>> adj;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        for (auto& v: meetings) {
            int a = v[0], b = v[1], t = v[2];
            adj[t][a].push_back(b);
            adj[t][b].push_back(a);
        }
        vector<int> flag(n);
        flag[0] = true; flag[firstPerson] = true;
        for (auto& [t, edges]: adj) {
            queue<int> q;
            set<int> vis;
            for (auto& [start, _]: edges) {
                if (flag[start]) {
                    q.push(start);
                    vis.insert(start);
                }
            }
            while (!q.empty()) {
                int u = q.front(); q.pop();
                flag[u] = true;
                for (auto& v: edges[u]) {
                    if (vis.find(v) == vis.end()) {
                        vis.insert(v);
                        q.push(v);
                    }
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (flag[i]) res.push_back(i);
        }
        return res;
    }

};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

