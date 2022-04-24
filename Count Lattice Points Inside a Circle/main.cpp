#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int res = 0, n = circles.size();
        for (int x = -100; x <= 200; x++) {
            for (int y = -100; y <= 200; y++) {
                bool flag = false;
                for (int i = 0; i < n; i++) {
                    if (inside(x, y, circles[i])) {
                        flag = true;
                        break;
                    }
                }
                if (flag) res++;
            }
        }
        return res;
    }

    bool inside(int x, int y, vector<int>& c) {
        int x0 = c[0], y0 = c[1], r = c[2];
        return (x - x0) * (x - x0) + (y - y0) * (y - y0) <= r * r;
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

