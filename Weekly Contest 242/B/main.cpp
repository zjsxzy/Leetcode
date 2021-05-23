#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    bool check(int speed, vector<int>& dist, double hour) {
        double sum = 0;
        int n = dist.size();
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                sum += (double)dist[i] / speed;
                continue;
            }
            int t = dist[i] / speed;
            if (dist[i] % speed != 0) {
                sum += t + 1;
            } else {
                sum += t;
            }
        }
        return sum <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo = 1, hi = 1e7, res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid, dist, hour)) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
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

