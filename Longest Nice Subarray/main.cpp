#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> b(32);
        for (auto& x: nums) {
            for (int i = 0; i < 31; i++) {
                if (x >> i & 1) b[i].push_back(1);
                else b[i].push_back(0);
            }
        }
        vector<vector<int>> sum(32, vector<int>(n));
        for (int i = 0; i < 31; i++) {
            sum[i][0] = b[i][0];
            for (int j = 1; j < n; j++) {
                sum[i][j] = sum[i][j - 1] + b[i][j];
            }
        }

        auto range_sum = [&](int i, int j, int k) {
            if (i == 0) return sum[k][j];
            return sum[k][j] - sum[k][i - 1];
        };

        auto check = [&](int k) {
            for (int i = 0; i < n; i++) {
                int j = i + k - 1;
                if (j >= n) continue;
                bool flag = true;
                for (int x = 0; x < 31; x++) {
                    if (range_sum(i, j, x) > 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
            return false;
        };

        int lo = 1, hi = n, res = 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
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
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

