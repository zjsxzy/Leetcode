#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int mod = 1e9 + 7;
class Solution {
public:
    int minNonZeroProduct(int p) {
        long long val = ((1LL << p) - 1) % mod;
        // cout << val << " " << ((1LL << p) - 2) / 2 << endl;
        long long t = (val - 1) % mod;
        long long res = quick(t, ((1LL << p) - 2) / 2);
        res = res * val % mod;
        return res;
    }

    long long quick(long long x, long long m) {
        // cout << x << "^" << m << "=";
        long long res = 1;
        for (; m; m >>= 1) {
            if (m & 1) res = res * x % mod;
            x = x * x % mod;
        }
        // cout << res << endl;
        return res;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

