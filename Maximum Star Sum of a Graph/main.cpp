#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<multiset<int>> adj(n);
        for (auto& e: edges) {
            adj[e[0]].insert(-vals[e[1]]);
            adj[e[1]].insert(-vals[e[0]]);
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = vals[i], sz = (int)adj[i].size();
            res = max(res, sum);
            for (int j = 0; j < min(k, sz); j++) {
                sum += -*adj[i].begin();
                adj[i].erase(adj[i].begin());
                res = max(res, sum);
            }
        }
        return res;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    (void)!freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

