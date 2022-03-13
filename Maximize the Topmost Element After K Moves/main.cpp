#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (k == 0) return nums[0];
        int n = nums.size();
        if (n == 1 && k % 2 == 1) return -1;
        int res = -1;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            bool flag = false;
            if (k == i) flag = true;
            else if (k > i) {
                int kk = k - i;
                if (kk > 1) flag = true;
                if (kk % 2 == 0) flag = true;
            }
            if (flag) res = max(res, x);
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

