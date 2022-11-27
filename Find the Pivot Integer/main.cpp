#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int pivotInteger(int n) {
        for (int x = 1; x <= n; x++) {
            int s1 = 0, s2 = 0;
            for (int i = 1; i <= x; i++) s1 += i;
            for (int i = x; i <= n; i++) s2 += i;
            if (s1 == s2) return x;
        }
        return -1;
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

