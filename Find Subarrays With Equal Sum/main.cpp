#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[i] + nums[i + 1] == nums[j] + nums[j + 1]) return true;
            }
        }
        return false;
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

