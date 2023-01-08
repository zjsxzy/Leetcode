#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, pos = 0;
        for (auto x: nums) {
            if (x > 0) pos++;
            if (x < 0) neg++;
        }
        return max(neg, pos);
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

