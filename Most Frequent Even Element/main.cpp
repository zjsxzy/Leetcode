#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> cnt;
        for (auto x: nums) cnt[x]++;
        int mx = 0, res = -1;
        for (auto [k, v]: cnt) {
            if (k % 2 == 0) {
                if (v > mx) {
                    mx = v;
                    res = k;
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
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

