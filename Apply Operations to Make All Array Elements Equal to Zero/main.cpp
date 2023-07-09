#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> add(n + 1);
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr -= add[i];
            nums[i] -= curr;
            if (nums[i] < 0) return false;
            else if (nums[i] > 0) {
                curr += nums[i];
                if (i + k <= n) {
                    add[i + k] += nums[i];
                }
            }

        }
        curr -= add[n];
        if (curr > 0) return false;
        return true;
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

