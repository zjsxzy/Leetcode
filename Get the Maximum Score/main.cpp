#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int mod = 1e9 + 7;
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        long long f = 0, g = 0;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                f += (long long)nums1[i];
                i++;
            } else if (nums1[i] > nums2[j]) {
                g += (long long)nums2[j];
                j++;
            } else { // nums1[i] == nums2[j]
                long long t = max(f, g);
                f = g = (t + (long long)nums1[i]) % mod;
                i++;
                j++;
            }
        }
        if (i < n) {
            for (; i < n; i++) {
                f += (long long)nums1[i];
            }
        }
        if (j < m) {
            for (; j < m; j++) {
                g += (long long)nums2[j];
            }
        }
        return max(f, g) % mod;
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

