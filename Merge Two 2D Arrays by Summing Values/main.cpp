#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> cnt;
        for (auto x: nums1) {
            cnt[x[0]] = x[1];
        }
        for (auto x: nums2) {
            cnt[x[0]] += x[1];
        }
        vector<vector<int>> ans;
        for (auto [k, v]: cnt) {
            ans.push_back({k, v});
        }
        return ans;
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

