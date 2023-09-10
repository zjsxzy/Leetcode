#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int a = abs(sx - fx), b = abs(sy - fy);
        if (sx == fx && sy == fy) {
            return t != 1;
        } else if (a < b) {
            if (t >= b - a + a) return true;
            return false;
        } else {
            if (t >= a - b + b) return true;
            return false;
        }
        return false;
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
       solve();
    }
    return 0;
}

