#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        multiset<int> st;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && (st.empty() || (*st.rbegin()) - (*st.begin()) <= 2)) {
                st.insert(nums[j]);
                j++;
            }
            if (*st.rbegin() - *st.begin() > 2) {
                j--;
                st.extract(nums[j]);
            }
            res += j - i;
            st.extract(nums[i]);
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

