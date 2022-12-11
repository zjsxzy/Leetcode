#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        set<long long> st;
        for (auto x: nums) st.insert(x);
        int res = -1;
        vector<int> vst(1e5 + 1);
        for (auto x: nums) {
            long long t = x;
            if (!vst[t]) {
                int i = 1;
                vst[t] = 1;
                while (st.count(t * t)) {
                    t = t * t;
                    vst[t] = 1;
                    i++;
                    res = max(res, i);
                }
            }
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

