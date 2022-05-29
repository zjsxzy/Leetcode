#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        vector<int> st, dp(n);
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() > 0 && nums[i] > nums[st.back()]) {
                dp[i] = max(dp[i] + 1, dp[st.back()]);
                st.pop_back();
            }
            // cout << i << ' ' << nums[i] << ' ' << dp[i] << endl;
            res = max(res, dp[i]);
            st.push_back(i);
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

