#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    const int mod = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        long long lcm = (long long)a * b / gcd(a, b);
        long long lo = 0, hi = (long long)min(a, b) * n;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (mid / a + mid / b - mid / lcm >= n) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo % mod;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

