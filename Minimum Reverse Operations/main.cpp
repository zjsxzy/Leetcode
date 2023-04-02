#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n, -1);
        if (k == 1) {
            ans[p] = 0;
            return ans;
        }

        unordered_set<int> ban;
        for (auto x: banned) ban.insert(x);

        set<int> st[2];
        for (int i = 0; i < n; i++) {
            if (i != p && ban.count(i) == 0) st[i % 2].insert(i);
        }

        queue<int> q;
        q.push(p);
        ans[p] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            int l = max(-(k - 1), k - 1 - u * 2);
            int r = min(k - 1, -(k - 1) + (n - u - 1) * 2);
            int x = (u + k - 1) % 2;
            auto it = st[x].lower_bound(u + l);
            while (it != st[x].end()) {
                if (*it > u + r) break;
                ans[*it] = ans[u] + 1;
                q.push(*it);
                it = st[x].erase(it);
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

