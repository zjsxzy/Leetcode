#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[i - 1]) continue;
            int l = 0, r = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] != nums[i]) {
                    if (nums[j] < nums[i]) l = -1;
                    else l = 1;
                    break;
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (nums[j] != nums[i]) {
                    if (nums[j] < nums[i]) r = -1;
                    else r = 1;
                    break;
                }
            }
            // cout << i << " " << nums[i] << " " << l << " " << r << endl;
            if (l && r && l == r) {
                res++;
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

