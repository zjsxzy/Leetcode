#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int> cnt;
        for (auto x: nums) cnt[x]++;
        int res = 0, left = 0;
        for (auto [k, v]: cnt) {
            if (v & 1) left++;
            res += v / 2;
        }
        vector<int> ans;
        ans.push_back(res);
        ans.push_back(left);
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

