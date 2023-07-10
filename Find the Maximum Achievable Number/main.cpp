#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + t * 2;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    (void)!freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

