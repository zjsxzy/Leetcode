#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int smallestValue(int n) {
        while (n) {
            int t = sum(n);
            if (t == n) return t;
            n = t;
        }
        return n;
    }

    int sum(int x) {
        int res = 0;
        for (int i = 2; i * i <= x; i++) {
            while (x % i == 0) {
                res += i;
                x /= i;
            }
        }
        if (x > 1) res += x;
        return res;
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

