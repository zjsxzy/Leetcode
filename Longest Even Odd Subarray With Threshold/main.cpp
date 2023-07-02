#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) continue;
            if (nums[i] > threshold) continue;
            res = max(res, 1);
            for (int j = i + 1; j < n; j++) {
                bool flag = true;
                for (int k = i; k <= j; k++) {
                    if (nums[k] > threshold || (k < j && nums[k] % 2 == nums[k + 1] % 2)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) res = max(res, j - i + 1);
            }
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

