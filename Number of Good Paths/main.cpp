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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        union_find uf(n);
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({vals[i], i});
        }
        sort(vec.begin(), vec.end());
        vector<vector<int>> adj(n);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = 0;
        for (int i = 0, j = 0; i < n; i) {
            vector<int> nodes;
            for (j = i; j < n && vec[j].first == vec[i].first; j++) {
                int u = vec[j].second;
                nodes.push_back(u);
                for (auto v: adj[u]) {
                    if (vals[v] <= vals[u] && !uf.same(u, v)) {
                        uf.unite(u, v);
                    }
                }
            }
            map<int, int> cnt;
            for (int k = i; k < j; k++) {
                int u = vec[k].second;
                cnt[uf.root(u)]++;
            }
            for (auto [k, v]: cnt) {
                res += v * (v - 1) / 2;
            }
            i = j;
        }
        return res + n;
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

