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
    int minScore(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        union_find dsu(n);
        vector<int> edges(n, INT_MAX);
        for (auto& e: roads) {
            e[0]--; e[1]--;
            dsu.unite(e[0], e[1]);
            edges[e[0]] = min(edges[e[0]], e[2]);
            edges[e[1]] = min(edges[e[1]], e[2]);
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dsu.same(i, 0) && dsu.same(i, n - 1)) {
                res = min(res, edges[i]);
            }
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
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

