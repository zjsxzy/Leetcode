#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> sum(n);
        sum[0] = stations[0];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + stations[i];
        }
        auto query = [&](int l, int r) {
            long long L, R;
            if (r >= n) R = sum[n - 1];
            else R = sum[r];
            if (l - 1 < 0) L = 0;
            else L = sum[l - 1];
            return R - L;
        };
        auto check = [&](long long x) {
            long long K = k, add = 0;
            vector<long long> diff(n);
            for (int i = 0; i < n; i++) {
                add -= diff[max(0, i - r - 1)];
                long long t = query(i - r, i + r) + add;
                if (t >= x) continue;
                if (t + K < x) return false;
                else {
                    diff[min(n - 1, i + r)] += x - t;
                    add += x - t;
                    K -= x - t;
                    if (K < 0) return false;
                }
            }
            return true;
        };
        long long lo = 0, hi = 1LL << 60, res;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (check(mid)) {
                lo = mid + 1;
                res = mid;
            } else {
                hi = mid - 1;
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

