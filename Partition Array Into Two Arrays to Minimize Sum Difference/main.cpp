#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        n /= 2;
        int sum = 0;
        for (int i = 0; i < 2 * n; i++) {
            sum += nums[i];
        }

        vector<int> f(1 << n), g(1 << n);
        vector<vector<int>> fs(n + 1), gs(n + 1);
        for (int s = 0; s < (1 << n); s++) {
            int b = 0;
            for (int i = 0; i < n; i++) {
                if (s & (1 << i)) {
                    b++;
                    f[s] += nums[i];
                    g[s] += nums[i + n];
                }
            }

            fs[b].push_back(f[s]);
            gs[b].push_back(g[s]);
        }

        for (int i = 0; i <= n; i++) {
            sort(fs[i].begin(), fs[i].end());
            sort(gs[i].begin(), gs[i].end());
        }

        int res = INT_MAX;
        for (int i = 0; i <= n; i++) {
            for (auto x: fs[i]) {
                auto y = lower_bound(gs[n - i].begin(), gs[n - i].end(), sum / 2 - x);
                if (y != gs[n - i].end()) {
                    int s1 = x + *y;
                    int s2 = sum - s1;
                    res = min(res, abs(s1 - s2));

                }
                if (y != gs[n - i].begin()) {
                    y--;
                    int s1 = x + *y;
                    int s2 = sum - s1;
                    int res = min(res, abs(s1 - s2));
                }

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
    solve();
    return 0;
}

