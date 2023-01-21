#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {nums2[i], nums1[i]};
        }
        sort(vec.begin(), vec.end());
        long long sum = 0, res = 0;
        multiset<long long> st;
        for (int i = n - 1; i >= 0; i--) {
            st.insert(vec[i].second);
            sum += vec[i].second;
            // cout << vec[i].first << ' ' << vec[i].second << ' ' << sum << endl;
            if (st.size() > k) {
                auto x = *st.begin();
                sum -= x;
                st.erase(st.begin());
            }
            if (st.size() == k) res = max(res, sum * vec[i].first);
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

