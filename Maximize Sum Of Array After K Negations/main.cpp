#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int neg = 0, abs_min = INT_MAX, sum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0 && i < k) {
                neg++;
                sum += -nums[i];
            } else {
                sum += nums[i];
            }
            abs_min = min(abs_min, abs(nums[i]));
        }
        if (k <= neg) {
            return sum;
        } else{
            k -= neg;
            if (k % 2 == 0) {
                return sum;
            } else {
                return sum - 2 * abs_min;
            }
        }
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

