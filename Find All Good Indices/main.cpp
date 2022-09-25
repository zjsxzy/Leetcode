#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n), g(n);
        f[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) f[i] = 1;
            else f[i] = f[i - 1] + 1;
        }
        g[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) g[i] = 1;
            else g[i] = g[i + 1] + 1;
        }
        vector<int> ans;
        for (int i = 1; i < n - 1; i++) {
            // cout << i << ' ' << f[i] << ' ' << g[i] << endl;
            if (f[i - 1] >= k && g[i + 1] >= k) ans.push_back(i);
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

