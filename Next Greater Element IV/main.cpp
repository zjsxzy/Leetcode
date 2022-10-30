#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> id(n);
        for (int i = 0; i < n; i++) id[i] = i;
        sort(id.begin(), id.end(), [&](int i, int j) {
            if (nums[i] != nums[j]) return nums[i] > nums[j];
            return i < j;
        });
        vector<int> ans(n, -1);
        set<int> st;
        for (int i = 0; i < n; i++) {
            int j = id[i];
            auto x = st.lower_bound(j);
            if (x != st.end()) {
                x++;
                if (x != st.end()) ans[j] = nums[*x];
            }
            st.insert(j);
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

