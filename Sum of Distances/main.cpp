#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        map<int, long long> sum, cnt;
        for (int i = 0; i < n; i++) {
            ans[i] += cnt[nums[i]] * i - sum[nums[i]];
            sum[nums[i]] += i;
            cnt[nums[i]]++;
        }
        sum.clear(); cnt.clear();
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += sum[nums[i]] - cnt[nums[i]] * i;
            sum[nums[i]] += i;
            cnt[nums[i]]++;
        }
        return ans;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

