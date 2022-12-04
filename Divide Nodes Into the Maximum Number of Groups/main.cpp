#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct union_find{
    int N;
    vector<int> par, siz;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        for(int i=0; i<N; i++) par[i] = i;
    }
    int root(int X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y){
        return root(X) == root(Y);
    }
    void unite(int X, int Y){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
};

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        union_find dsu(n);
        for (auto& e: edges) {
            e[0]--; e[1]--;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            dsu.unite(e[0], e[1]);
        }

        auto calc = [&](int u) {
            int res = -1;
            for (int i = 0; i < n; i++) {
                if (dsu.same(i, u)) {
                    queue<int> q;
                    q.push(i);
                    vector<int> d(n, -1);
                    d[i] = 0;
                    int max_dep = 0;
                    bool flag = true;
                    while (!q.empty()) {
                        int u = q.front(); q.pop();
                        max_dep = max(max_dep, d[u]);
                        if (!flag) break;
                        for (auto v: adj[u]) {
                            if (d[v] == -1) {
                                d[v] = d[u] + 1;
                                q.push(v);
                            } else if (d[v] == d[u]) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        res = max(res, max_dep + 1);
                    }
                }
            }
            return res;
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.root(i) == i) {
                int t = calc(i);
                if (t == -1) return -1;
                ans += t;
            }
        }
        return ans;
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

