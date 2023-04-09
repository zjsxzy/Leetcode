#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i][i] > 1 && prime(nums[i][i])) res = max(res, nums[i][i]);
            if (nums[i][n - i - 1] > 1 && prime(nums[i][n - i - 1])) res = max(res, nums[i][n - i - 1]);
        }
        return res;
    }

    bool prime(int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

