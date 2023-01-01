#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int mode, mode_cnt = 0, n = nums1.size(), swap_cnt = 0;
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            int x = nums1[i];
            if (x == nums2[i]) {
                ans += i;
                swap_cnt++;
                cnt[x]++;
                if (cnt[x] > mode_cnt) {
                    mode = x;
                    mode_cnt = cnt[x];
                }
            }
        }
        for (int i = 0; i < n && mode_cnt * 2 > swap_cnt; i++) {
            int x = nums1[i], y = nums2[i];
            if (x != y && x != mode && y != mode) {
                ans += i;
                swap_cnt++;
            }
        }
        return mode_cnt * 2 > swap_cnt ? -1 : ans;
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

