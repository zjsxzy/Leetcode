#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size(), m = nums[0].size();
        for (auto q: queries) {
            int k = q[0], trim = q[1];
            vector<pair<string, int>> vec;
            for (int i = 0; i < n; i++) {
                string s = nums[i].substr(m - trim, trim);
                vec.push_back({s, i});
            }
            sort(vec.begin(), vec.end());
            ans.push_back(vec[k - 1].second);
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

