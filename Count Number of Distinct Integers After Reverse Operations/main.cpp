#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int t = rev(nums[i]);
            // cout << x << ' ' << t << endl;
            nums.push_back(t);
        }
        set<int> st;
        for (auto x: nums) st.insert(x);
        return (int)st.size();
    }
    int rev(int x) {
        int res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
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

