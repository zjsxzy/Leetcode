#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a(n + 1);
        for (int i = 0; i < n; i++) {
            a[i + 1] = nums[i];
        }

        vector<long long> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i];
        }

        vector<int> left(n + 1), right(n + 1);
        for (int i = 1; i <= n; i++) {
            left[i] = i - 1;
            while (left[i] >= 1 && a[left[i]] >= a[i]) {
                left[i] = left[left[i]];
            }
        }
        for (int i = n; i >= 1; i--) {
            right[i] = i + 1;
            while (right[i] <= n && a[right[i]] >= a[i]) {
                right[i] = right[right[i]];
            }
        }

        long long res = 0;
        for (int i = 1; i <= n; i++) {
            // cout << i << " " << a[i] << " " << left[i] << " " << right[i] << endl;
            res = max(res, (long long)a[i] * (sum[right[i] - 1] - sum[left[i]]));
        }
        long long mod = 1e9 + 7;
        return res % mod;
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

