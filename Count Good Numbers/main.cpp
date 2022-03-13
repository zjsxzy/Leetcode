#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const long long mod = 1e9 + 7;
class Solution {
public:
    int countGoodNumbers(long long n) {
        long long p = 20;
        long long m = n / 2;
        long long res = 1;
        for (; m; m >>= 1) {
            if (m & 1) res = res * p % mod;
            p = p * p % mod;
        }
        if (n & 1) {
            res = res * 5LL % mod;
        }
        return res;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

