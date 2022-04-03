#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long sum = 0;
        int mn = INT_MAX;
        for (auto c: candies) {
            sum += c;
            mn = min(mn, c);
        }
        if (sum < k) return 0;
        long long lo = 1, hi = sum, res = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (check(candies, k, mid)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }

    bool check(vector<int>& candies, long long k, long long num) {
        long long res = 0;
        for (auto c: candies) {
            res += c / num;
        }
        return res >= k;
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

