#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n == 2) return true;
        vector<int> st;
        for (auto a: nums) {
            st.push_back(a);
            while (st.size() >= 2) {
                int x = st[st.size() - 1], y = st[st.size() - 2];
                if (x + y >= m) {
                    st.pop_back(); st.pop_back();
                    st.push_back(x + y);
                } else {
                    break;
                }
            }
        }
        return st.size() == 1;
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

