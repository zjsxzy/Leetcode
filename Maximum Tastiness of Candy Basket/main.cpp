#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int lo = 0, hi = 1e9, res;
        auto check = [&](int d) {
            int i = 0;
            for (int j = 0; j < k - 1; j++) {
                auto x = lower_bound(price.begin(), price.end(), price[i] + d) - price.begin();
                if (x == n || price[x] - price[i] < d) return false;
                i = x;
            }
            return true;
        };
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid)) {
                res = mid;
                lo = mid + 1;
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

