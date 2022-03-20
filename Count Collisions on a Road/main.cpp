#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        if (n == 0) return 0;
        int res = 0;
        string d = "";
        for (int i = 0; i < n; ) {
            if (i < n && directions[i] == 'R' && directions[i + 1] == 'L') {
                d += 'S';
                res += 2;
                i += 2;
            } else {
                d += directions[i];
                i++;
            }
        }
        int m = d.size();
        bool left = false;
        for (int i = 0; i < m; i++) {
            if (left && d[i] == 'L') res++;
            if (d[i] == 'S') left = true;
        }
        bool right = false;
        for (int i = m - 1; i >= 0; i--) {
            if (right && d[i] == 'R') res++;
            if (d[i] == 'S') right = true;
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

