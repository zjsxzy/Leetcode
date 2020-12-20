#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(10001);
        int res = 0, sum = 0;
        for (int l = 0, r = 0; l < n; l++) {
            while (r < n) {
                if (cnt[nums[r]] != 0) {
                    break;
                }
                cnt[nums[r]]++;
                sum += nums[r];
                r++;
            }
            // cout << l << " " << r << " " << sum << endl;
            res = max(res, sum);
            cnt[nums[l]]--;
            sum -= nums[l];
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

