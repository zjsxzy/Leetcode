#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        const int mod = 1e9 + 7;
        vector<int> v;
        int i = 0;
        for (; i < n; i++) {
            if (nums[i] == 1) break;
        }
        if (i == n) return 0;

        i++;
        int curr = 0;
        for (; i < n; i++) {
            if (nums[i] == 1) {
                v.push_back(curr);
                curr = 0;
            } else {
                curr++;
            }
        }
        if (v.size() == 0) return 1;

        long long res = 1;
        for (auto x: v) {
            res *= (long long)(x + 1);
            res %= mod;
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

