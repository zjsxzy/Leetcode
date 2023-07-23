#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        long long res = 0, curr = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= curr) {
                curr += nums[i];
            } else {
                res = max(res, curr);
                curr = nums[i];
            }
        }
        res = max(res, curr);
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

