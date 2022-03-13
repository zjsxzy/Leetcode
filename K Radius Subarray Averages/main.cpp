#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> s(n + 1);
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (i - k <= 0) res.push_back(-1);
            else if (i + k > n) res.push_back(-1);
            else {
                long long sum = s[i + k] - s[i - k - 1];
                // cout << i << " " << i - k << " " << i + k << " " << sum << endl;
                res.push_back(sum / (2 * k + 1));
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

