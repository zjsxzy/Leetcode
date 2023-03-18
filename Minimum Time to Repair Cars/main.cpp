#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long lo = 0, hi = (long long) cars * cars * 100, res;
        auto check = [&](long long k) {
            long long sum = 0;
            for (auto r: ranks) {
                long long t = sqrt(k / r);
                sum += t;
            }
            return sum >= cars;
        };
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (check(mid)) {
                hi = mid - 1;
                res = mid;
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
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

