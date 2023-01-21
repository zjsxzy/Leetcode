#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:

    bool isReachable(int X, int Y) {
        while (X % 2 == 0) {
            X /= 2;
        }
        while (Y % 2 == 0) {
            Y /= 2;
        }
        return gcd(X, Y) == 1;
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

