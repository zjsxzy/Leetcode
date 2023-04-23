#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> cnt(105);
        int base = 50;
        for (int i = 0; i < k; i++) {
            cnt[nums[i] + base]++;
        }

        vector<int> ans;
        int tot = 0, p;
        for (int j = 0; j <= 100; j++) {
            tot += cnt[j];
            if (tot >= x) {
                p = j;
                break;
            }
        }
        if (p < base) ans.push_back(p - base);
        else ans.push_back(0);
        for (int i = k; i < n; i++) {
            cnt[nums[i - k] + base]--;
            cnt[nums[i] + base]++;
            tot = 0;
            for (int j = 0; j <= 100; j++) {
                tot += cnt[j];
                if (tot >= x) {
                    p = j;
                    break;
                }
            }
            if (p < base) ans.push_back(p - base);
            else ans.push_back(0);
        }
        return ans;
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

