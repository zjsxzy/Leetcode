#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MIN));
        sort(events.begin(), events.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        dp[0][0] = 0;
        dp[0][1] = events[0][2];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                // 不参加
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }

            // 参加
            int lo = 0, hi = i - 1, idx = -1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (events[mid][1] < events[i][0]) {
                    lo = mid + 1;
                    idx = mid;
                } else {
                    hi = mid - 1;
                }
            }
            if (idx == -1) { // 不存在这样一个位置
                dp[i][1] = max(dp[i][1], events[i][2]);
            } else {
                for (int j = 1; j <= k; j++) {
                    dp[i][j] = max(dp[i][j], dp[idx][j - 1] + events[i][2]);
                }
            }
            // cout << i << " " << idx << " " << dp[i][1] << endl;
        }

        int res = 0;
        for (int j = 0; j <= k; j++) {
            res = max(res, dp[n - 1][j]);
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

