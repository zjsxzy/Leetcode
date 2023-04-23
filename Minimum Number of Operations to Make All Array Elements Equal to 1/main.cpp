#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 1) {
                cnt++;
            }
        }
        if (cnt == 0) return 0;

        bool flag = false;
        int res = n;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    res = min(res, j - i);
                    flag = true;
                    break;
                }
            }
        }
        if (flag) return cnt + res - 1;
        else return -1;
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

