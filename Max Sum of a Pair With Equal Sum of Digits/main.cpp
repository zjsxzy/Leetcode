#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, vector<int>> cnt;
        for (auto x: nums) {
            int t = 0, y = x;
            while (x) {
                t += x % 10;
                x /= 10;
            }
            cnt[t].push_back(y);
        }
        int res = -1;
        for (auto [k, v]: cnt) {
            if (v.size() < 2) continue;
            sort(v.begin(), v.end());
            int m = v.size();
            res = max(res, v[m - 1] + v[m - 2]);
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
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

