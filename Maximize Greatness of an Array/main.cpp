#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        multiset<int> st;
        for (auto x: vec) st.insert(x.first);
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            auto x = st.lower_bound(vec[i].first + 1);
            if (x != st.end()) {
                ans[vec[i].second] = *x;
                st.erase(x);
            }
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1) {
                ans[i] = *st.begin();
                st.erase(st.begin());
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += ans[i] > nums[i];
        }
        return res;
    }
};

void solve() {
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

