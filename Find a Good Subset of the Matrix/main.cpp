#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> v(32, -1);
        for (int i = 0; i < m; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                s |= (grid[i][j] << j);
            }
            v[s] = i;
        }
        if (v[0] != -1) return {v[0]};
        for (int i = 0; i < (1 << n); i++) {
            for (int j = i; j < (1 << n); j++) {
                if ((i & j) == 0 && v[i] != -1 && v[j] != -1) {
                    vector<int> ans;
                    ans.push_back(v[i]);
                    ans.push_back(v[j]);
                    sort(ans.begin(), ans.end());
                    return ans;
                }
            }
        }
        return {};
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    (void)!freopen("in.txt", "r", stdin);
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

