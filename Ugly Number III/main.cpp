#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long lcmab = (long long)a * b / gcd(a, b);
        long long lcmbc = (long long)b * c / gcd(b, c);
        long long lcmac = (long long)a * c / gcd(a, c);
        long long lcmabc = lcmab * c / gcd(lcmab, c);
        long long lo = 0, hi = (long long)min(min(a, b), c) * n;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (mid / a + mid / b + mid / c \
                - mid / lcmab - mid / lcmbc - mid / lcmac \
                + mid / lcmabc >= n) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
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

