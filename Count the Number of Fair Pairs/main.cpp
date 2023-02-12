#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        for (auto x: nums) {
            int r = upper_bound(nums.begin(), nums.end(), upper - x) - nums.begin();
            int l = lower_bound(nums.begin(), nums.end(), lower - x) - nums.begin();
            res += r - l;
            if (lower <= 2 * x && 2 * x <= upper) res--;
        }
        return res / 2;
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

