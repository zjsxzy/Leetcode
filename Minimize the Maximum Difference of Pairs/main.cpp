#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        auto check = [&](int k) {
            int res = 0;
            if (res >= p) return true;
            vector<int> vst(n);
            for (int i = 0; i < n - 1; i++) {
                if (vst[i]) continue;
                if (nums[i + 1] <= nums[i] + k) {
                    res++;
                    vst[i] = true;
                    vst[i + 1] = true;
                }
                if (res >= p) return true;
            }
            return false;
        };

        int lo = 0, hi = 1e9, res;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid)) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

