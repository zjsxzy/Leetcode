#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        map<int, int> cnt;
        for (auto x: nums) {
            cnt[gcd(x, k)]++;
        }
        vector<pair<int, long long>> v;
        for (auto c: cnt) v.push_back(c);
        long long res = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (1LL * v[i].first * v[j].first % k == 0) {
                    if (i == j) res += v[i].second * (v[i].second - 1) / 2;
                    else res += v[i].second * v[j].second;
                }
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

