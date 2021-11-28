#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), mn = INT_MAX, mx = INT_MIN, mn_i = -1, mx_i = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > mx) {
                mx = nums[i]; mx_i = i;
            }
            if (nums[i] < mn) {
                mn = nums[i]; mn_i = i;
            }
        }
        mx_i++; mn_i++;
        int res = max(mx_i, mn_i);
        res = min(res, max(n - mn_i + 1, n - mx_i + 1));
        res = min(res, mx_i + n - mn_i + 1);
        res = min(res, mn_i + n - mx_i + 1);
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

