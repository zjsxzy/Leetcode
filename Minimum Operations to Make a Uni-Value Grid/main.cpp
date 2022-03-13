#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        vector<int> num;
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                num.push_back(grid[i][j]);
                sum += grid[i][j];
            }
        sort(num.begin(), num.end());
        n = num.size();
        if (n == 1) return 0;
        int res = INT_MAX;
        for (int i = max(0, n / 2 - 1); i < min(n - 1, n / 2 + 1); i++) {
            int target = num[i];
            int sum = 0;
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (abs(num[j] - target) % x == 0) {
                    sum += abs(num[j] - target) / x;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) res = min(res, sum);
        }
        if (res == INT_MAX) res = -1;
        return res;
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

