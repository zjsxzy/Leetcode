#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> sum1(n + 1), sum2(n + 1);
        int ss1 = 0, ss2 = 0;
        for (int i = 0; i < n; i++) {
            sum1[i + 1] = sum1[i] - nums1[i] + nums2[i];
            sum2[i + 1] = sum2[i] - nums2[i] + nums1[i];
            ss1 += nums1[i]; ss2 += nums2[i];
        }
        int res = max(ss1, ss2);
        int s1 = INT_MAX, s2 = INT_MAX;
        for (int i = 1; i <= n; i++) {
            // cout << i << ' ' << sum1[i] << ' ' << sum2[i] << endl;
            res = max(res, ss1 + sum1[i] - s1);
            res = max(res, ss2 + sum2[i] - s2);
            if (sum1[i] < s1) s1 = sum1[i];
            if (sum2[i] < s2) s2 = sum2[i];
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

