#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int l = k, r = k, res = 0;
        while (true) {
            while (l >= 0 && nums[l] >= nums[k]) l--;
            while (r < n && nums[r] >= nums[k]) r++;
            res = max(res, (r - l - 1) * nums[k]);
            if (l < 0 && r == n) break;
            if (l >= 0 && r < n) nums[k] = max(nums[l], nums[r]);
            else if (l < 0) nums[k] = nums[r];
            else nums[k] = nums[l];
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

