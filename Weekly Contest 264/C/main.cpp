#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
vector<int> adj[maxn];
int n;
int cnt[maxn];
long long prod[maxn];
class Solution {
public:

    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            cnt[i] = 0;
            prod[i] = 1;
        }
        for (int i = 1; i < n; i++) {
            adj[i].push_back(parents[i]);
            adj[parents[i]].push_back(i);
        }
        dfs(0, -1);
        for (int i = 1; i < n; i++) {
            // cout << i << " " << cnt[i] << " " << n - 1 << " " << cnt[i] << endl;
            prod[i] *= (n - cnt[i]);
        }
        long long mx = 0;
        for (int i = 0; i < n; i++) mx = max(mx, prod[i]);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (prod[i] == mx) res++;
        }
        return res;
    }

    void dfs(int u, int p) {
        for (auto v: adj[u]) {
            if (v != p) {
                dfs(v, u);
                cnt[u] += cnt[v];
                prod[u] *= cnt[v];
            }
        }
        cnt[u]++;
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

