#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct union_find {
    int n;
    vector<set<int>> groups;
    vector<int> owner;
    union_find(int n_) : n(n_){
        groups.assign(n, {});
        owner.resize(n);
        for (int i = 0; i < n; i++) {
            owner[i] = i;
            groups[i] = {i};
        }
    }
    void unite(int a, int b) {
        a = owner[a];
        b = owner[b];
        if (a == b) return;
        if (groups[a].size() > groups[b].size()) swap(a, b);
        for (int x : groups[a]) {
            owner[x] = b;
            groups[b].insert(x);
        }
        groups[a].clear();
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        union_find dsu(n);
        vector<vector<int>> g(n, vector<int>(n));
        for (auto e: edges) {
            g[e[0]][e[1]] = g[e[1]][e[0]] = 1;
            dsu.unite(e[0], e[1]);
        }
        int res = 0;
        for (auto st: dsu.groups) {
            if (st.size() == 0) continue;
            vector<int> v;
            for (auto u: st) {
                v.push_back(u);
            }
            int sz = v.size();
            bool flag = true;
            for (int i = 0; i < sz; i++) {
                for (int j = i + 1; j < sz; j++) {
                    if (!g[v[i]][v[j]]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) res++;
        }
        return res;
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

