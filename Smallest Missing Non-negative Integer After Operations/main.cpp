#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> cnt(max(n, value) + 1);
        for (auto& x: nums) {
            if (x < 0) {
                int t = -x / value;
                x += t * value;
                if (x < 0) x += value;
            } else if (x > 0) {
                int t = x / value;
                x -= t * value;
            }
            cnt[x]++;
        }
        for (int i = 0; i < max(n, value); i++) {
            if (!cnt[i]) return i;
            if (cnt[i] > 1 && i + value < max(n, value)) {
                cnt[i + value] += (cnt[i] - 1);
                cnt[i] -= (cnt[i] - 1);
            }
        }
        return max(n, value);
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

