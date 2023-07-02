#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            multiset<int> st;
            int curr = 0;
            for (int j = i; j < n; j++) {
                auto x = st.lower_bound(nums[j]);
                int prev = -1, next = -1;
                if (x != st.begin()) {
                    x--;
                    prev = *x;
                }
                x = st.lower_bound(nums[j]);
                if (x != st.end()) {
                    next = *x;
                }
                if (prev != -1) {
                    curr += (nums[j] - prev > 1);
                }
                if (next != -1) {
                    curr += (next - nums[j] > 1);
                }
                if (prev != -1 && next != -1) {
                    curr -= (next - prev > 1);
                }
                res += curr;
                st.insert(nums[j]);
            }
        }
        return res;
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

