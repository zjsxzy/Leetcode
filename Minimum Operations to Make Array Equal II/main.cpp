#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = nums1[i] - nums2[i];
        }
        if (k == 0) {
            for (auto x: diff) if (x != 0) return -1;
            return 0;
        }
        long long pos = 0, neg = 0;
        for (auto x: diff) {
            if (abs(x) % k != 0) return -1;
            if (x > 0) pos += x;
            else neg += x;
        }
        if (pos + neg == 0) return pos / k;
        return -1;
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

