#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> f(n);
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }
        function<void(int ,int)> dfs = [&](int u, int mask) {
            f[u] = mask;
            for (auto v: g[u]) {
                dfs(v, mask ^ (1 << (s[v] - 'a')));
            }
        };
        dfs(0, 0);
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[f[i]]++;
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                res += cnt[f[i] ^ (1 << j)];
            }
            res += cnt[f[i]] - 1;
        }
        return res / 2;
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

