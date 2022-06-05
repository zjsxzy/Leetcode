#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 1, curr = nums[0], n = nums.size();
        if (n == 1) return 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] - curr > k) {
                res++;
                curr = nums[i];
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

