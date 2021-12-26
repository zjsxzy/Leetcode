#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        vector<int> poss_k;
        sort(nums.begin(), nums.end());
        int n = nums.size() / 2;
        for (int i = 1; i < 2 * n; i++) {
            int k = (nums[i] - nums[0]);
            if (k > 0 && k % 2 == 0) poss_k.push_back(k / 2);
        }
        map<int, int> cnt, curr;
        for (auto x: nums) {
            cnt[x]++;
        }
        vector<int> res;
        for (auto k: poss_k) {
            curr = cnt;
            bool ok = true;
            for (int i = 2 * n - 1; i >= 0; i--) {
                if (curr[nums[i]] > 0) {
                    if (curr.find(nums[i] - 2 * k) == curr.end() || curr[nums[i] - 2 * k] <= 0) {
                        ok = false;
                        break;
                    } else {
                        curr[nums[i]]--;
                        curr[nums[i] - 2 * k]--;
                    }
                }
            }
            if (ok) {
                curr = cnt;
                for (int i = 2 * n - 1; i >= 0; i--) {
                    if (curr[nums[i]] > 0) {
                        res.push_back(nums[i] - k);
                        curr[nums[i]]--;
                        curr[nums[i] - 2 * k]--;
                    }
                }
                return res;
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
    solve();
    return 0;
}

