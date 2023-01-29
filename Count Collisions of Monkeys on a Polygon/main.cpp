#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

typedef long long LL;

const int mod = 1e9 + 7;
class Solution {
public:
    int monkeyMove(int n) {
        return (quickpow(2, n, mod) - 2 + mod) % mod;
    }

    LL quickpow(LL x, LL n, LL mod) {
        LL res = 1;
        for (; n; n >>= 1) {
            if (n & 1) res = res * x % mod;
            x = x * x % mod;
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

