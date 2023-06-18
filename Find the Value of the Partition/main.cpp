#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[n - 1] - nums[0];
        for (int i = 1; i < n; i++) {
            res = min(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
       solve();
    }
    return 0;
}

