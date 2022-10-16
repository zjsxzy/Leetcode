#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int sum = 0;
        for (auto x: nums) sum += x;
        vector<vector<int>> adj(n);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = 0, need;
        bool flag;
        vector<int> w(n);
        function<void(int, int)> dfs = [&](int u, int p) {
            if (!flag) return;
            w[u] = nums[u];
            for (auto v: adj[u]) {
                if (v == p) continue;
                dfs(v, u);
                w[u] += w[v];
            }
            if (w[u] > need) flag = false;
            if (w[u] == need) w[u] = 0;
        };
        for (int i = 1; i <= sum; i++) {
            if (sum % i != 0) continue;
            flag = true;
            need = sum / i;
            dfs(0, -1);
            if (flag) res = max(res, i - 1);
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

