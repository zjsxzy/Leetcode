#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> st;
        for (auto x: nums) st.insert(x);
        int res = 0;
        for (auto x: nums) {
            if (st.count(x) && st.count(-x)) res = max(res, x);
        }
        if (res == 0) res = -1;
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

