#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int vst[1005], n, diff, a[25];
class Solution {
public:
    int dfs(int k, int s) {
        if (k == n) {
            return 1;
        }
        int res = dfs(k + 1, s);
        bool flag = true;
        if (a[k] - diff >= 0 && vst[a[k] - diff]) flag = false;
        if (a[k] + diff <= 1000 && vst[a[k] + diff]) flag = false;
        if (flag) {
            vst[a[k]] = 1;
            res += dfs(k + 1, s | (1 << k));
            vst[a[k]] = 0;
        }
        return res;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        diff = k;
        n = nums.size();
        for (int i = 0; i < n; i++) a[i] = nums[i];
        for (int i = 0; i < 1005; i++) vst[i] = 0;
        int res = dfs(0, 0);
        return res - 1;
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

