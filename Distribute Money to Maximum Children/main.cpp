#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        int res = 0;
        for (int i = 0; i <= children; i++) {
            int t = money - i * 8 - (children - i);
            if (t < 0) continue;
            if (t == 3 && children - i == 1) continue;
            if (t > 0 && children - i == 0) continue;
            res = max(res, i);
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

