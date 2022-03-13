#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int d = 0; d <= k; d++) {
                if (i + d < n && nums[i + d] == key) {
                    flag = true;
                    break;
                }
            }
            for (int d = 0; d <= k; d++) {
                if (i - d >= 0 && nums[i - d] == key) {
                    flag = true;
                    break;
                }
            }
            if (flag) res.push_back(i);
        }
        return res;
    }

};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

