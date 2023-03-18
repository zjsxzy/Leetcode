#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int, int>> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            st.insert({nums[i], i});
        }
        vector<int> vst(n);
        long long res = 0;
        while (!st.empty()) {
            auto x = st.begin();
            res += x->first;
            int i = x->second;
            vst[i] = true;
            st.erase(x);
            if (i + 1 < n && !vst[i + 1]) {
                st.erase({nums[i + 1], i + 1});
                vst[i + 1] = true;
            }
            if (i - 1 >= 0 && !vst[i - 1]) {
                st.erase({nums[i - 1], i - 1});
                vst[i - 1] = true;
            }
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

