#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        if (n == 1) {
            sort(nums[0].begin(), nums[0].end());
            return nums[0];
        }
        vector<int> res;
        for (auto x: nums[0]) {
            bool flag = true;
            for (int i = 1; i < n; i++) {
                bool f = false;
                for (int j = 0; j < nums[i].size(); j++) {
                    if (x == nums[i][j]) {
                        f = true;
                        break;
                    }
                }
                if (!f) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(x);
        }
        sort(res.begin(), res.end());
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

