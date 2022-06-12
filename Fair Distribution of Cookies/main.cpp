#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<vector<int>> has;
    vector<int> c;
    int n, k, res;
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        has.assign(n, {});
        this->k = k;
        c = cookies;
        res = INT_MAX;
        dfs(0);
        return res;
    }

    void dfs(int p) {
        if (p == n) {
            int mx = 0;
            for (int i = 0; i < k; i++) {
                if (has[i].size() == 0) return;
                int sum = 0;
                for (auto x: has[i]) sum += c[x];
                mx = max(mx, sum);
            }
            res = min(res, mx);
            return;
        }
        for (int i = 0; i < k; i++) {
            has[i].push_back(p);
            dfs(p + 1);
            has[i].pop_back();
        }
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

