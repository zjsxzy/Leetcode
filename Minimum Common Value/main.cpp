#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        for (auto x: nums1) st.insert(x);
        sort(nums2.begin(), nums2.end());
        for (auto x: nums2) {
            if (st.count(x)) return x;
        }
        return -1;
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

