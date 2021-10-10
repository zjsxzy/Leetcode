#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> st1, st2, st3;
        vector<int> nums;
        for (auto x: nums1) {
            st1.insert(x);
            nums.push_back(x);
        }
        for (auto x: nums2) {
            st2.insert(x);
            nums.push_back(x);
        }
        for (auto x: nums3) {
            st3.insert(x);
            nums.push_back(x);
        }
        set<int> st;
        for (auto x: nums) {
            int t = 0;
            if (st1.find(x) != st1.end()) t++;
            if (st2.find(x) != st2.end()) t++;
            if (st3.find(x) != st3.end()) t++;
            if (t >= 2) st.insert(x);
        }
        vector<int> res;
        for (auto x: st) {
            res.push_back(x);
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
    solve();
    return 0;
}

