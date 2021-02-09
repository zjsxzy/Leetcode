#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int half = n / 2;
        int ls = half, rs = n - half;
        vector<int> lsum(1 << ls, 0);
        for (int i = 0; i < (1 << ls); i++) {
            for (int j = 0; j < ls; j++) {
                if ((i >> j) & 1) {
                    lsum[i] = lsum[i ^ (1 << j)] + nums[j];
                }
            }
        }
        vector<int> rsum(1 << rs, 0);
        for (int i = 0; i < (1 << rs); i++) {
            for (int j = 0; j < rs; j++) {
                if ((i >> j) & 1) {
                    rsum[i] = rsum[i ^ (1 << j)] + nums[half + j];
                }
            }
        }

        sort(lsum.begin(), lsum.end());
        sort(rsum.begin(), rsum.end());

        int res = INT_MAX;
        for (auto& x : lsum) {
            res = min(res, abs(goal - x));
        }
        for (auto& x : rsum) {
            res = min(res, abs(goal - x));
        }

        int l = 0, r = rsum.size() - 1;
        while (l < lsum.size() && r >= 0) {
            int sum = lsum[l] + rsum[r];
            res = min(res, abs(goal - sum));
            if (sum > goal) {
                r--;
            } else {
                l++;
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

