#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0, dig = 0;
        for (auto x: nums) {
            sum += x;
            while (x) {
                dig += x % 10;
                x /= 10;
            }
        }
        return abs(sum - dig);
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

