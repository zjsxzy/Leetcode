#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size(), curr = 0, previ = -1;
        map<int, int> cnt;
        long long res = 0;
        for (int i = 0, j = 0; i < n; ) {
            while (curr < k && j < n) {
                curr += cnt[nums[j]];
                cnt[nums[j]]++;
                j++;
            }
            if (curr >= k) {
                res += (long long)(i - previ) * (n - j + 1);
                previ = i;
            }
            cnt[nums[i]]--;
            curr -= max(0, cnt[nums[i]]);
            i++;
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

