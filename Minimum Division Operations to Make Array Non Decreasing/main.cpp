#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int mx = 0;
        for (auto x: nums) mx = max(mx, x);
        vector<int> prime(mx + 1);
        for (int i = 2; i <= mx; i++) {
            if (!prime[i]) {
                for (int j = i; j <= mx; j += i) {
                    if (!prime[j]) prime[j] = i;
                }
            }
        }
        int res = 0;
        for (int i = n - 2; i >= 0; i--) {
            int x = nums[i], y = nums[i + 1];
            if (x > y) {
                if (!prime[x]) return -1;
                x = prime[x];
                if (x > y) return -1;
                res++;
            }
            nums[i] = x;
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

