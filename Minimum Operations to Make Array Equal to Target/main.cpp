#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long s = target[0] - nums[0];
        long long res = abs(s);
        for (int i = 1; i < n; i++) {
            int t = (target[i] - target[i - 1]) - (nums[i] - nums[i - 1]);
            if (t > 0) {
                res += s >= 0 ? t : max(t + s, 0LL);
            } else {
                res -= s <= 0 ? t : min(t + s, 0LL);
            }
            s += t;
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

