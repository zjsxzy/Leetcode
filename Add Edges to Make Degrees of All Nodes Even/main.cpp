#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<set<int>> adj(n);
        for (auto& e: edges) {
            e[0]--; e[1]--;
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() & 1) v.push_back(i);
        }
        if (v.size() > 4) return false;
        if (v.size() & 1) return false;
        if (v.size() == 0) return true;
        if (v.size() == 2) {
            if (!adj[v[0]].count(v[1])) return true;
            for (int i = 0; i < n; i++) {
                if (i == v[0] || i == v[1]) continue;
                if (!adj[v[0]].count(i) && !adj[v[1]].count(i)) return true;
                return false;
            }
            return false;
        }
        if (v.size() == 4) {
            for (int i = 1; i < 4; i++) {
                if (!adj[v[0]].count(v[i])) {
                    for (int j = 1; j < 4; j++) {
                        for (int k = j + 1; k < 4; k++) {
                            if (j != i && k != i) {
                                if (!adj[v[j]].count(v[k])) return true;
                            }
                        }
                    }
                }
            }
            return false;
        }
        return false;
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

