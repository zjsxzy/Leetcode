#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = nums[i], y = nums[j];
                while (x >= 10) x /= 10;
                y %= 10;
                if (gcd(x, y) == 1) {
                    res++;
                }
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

