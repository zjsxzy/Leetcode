#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minOperations(int n) {
        int res = __builtin_popcount(n);
        for (int i = 1; i <= n; i++) {
            res = min(res, __builtin_popcount(n + i) + __builtin_popcount(i));
        }
        return res;
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

