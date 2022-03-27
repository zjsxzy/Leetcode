#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size(), res = 0;
        if (n == 1) return 1;
        int f = 0;
        for (int i = 0; i < n - 1; i++) {
            if (!f && i % 2 == 0 && nums[i] == nums[i + 1]) {
                cout << i << endl;
                res++;
                f ^= 1;
            } else if (f && i & 1 && nums[i] == nums[i + 1]) {
                cout << i << endl;
                res++;
                f ^= 1;
            }
        }
        // cout << f << " " << res << endl;
        if (n % 2 == 0 && f) res++;
        else if (n & 1 && !f) res++;
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

