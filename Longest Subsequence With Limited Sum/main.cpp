#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> ans(m);
        sort(nums.begin(), nums.end());
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (int i = 0; i < m; i++) {
            int j = 1;
            for (; j <= n; j++) {
                if (sum[j] > queries[i]) {
                    break;
                }
            }
            ans[i] = j - 1;
        }
        return ans;
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

