#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for (auto x: nums) mx = max(mx, x);
        int curr = 0, res = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == mx) {
                curr++;
            } else {
                curr = 0;
            }
            res = max(res, curr);
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

