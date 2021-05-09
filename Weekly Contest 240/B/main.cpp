#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;


class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        reverse(nums2.begin(), nums2.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            // cout << i << " " << it << endl;
            int l = n - i - 1;
            int r = m - it - 1;
            // cout << l << " " << r << " " << r - l << endl;
            if (r - l > res) res = r - l;
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

