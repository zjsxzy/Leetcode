#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int x = (1 << n) - 1;
        for (int i = x; i; i = (i - 1) & x) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    sum ^= nums[j];
                }
            }
            res += sum;
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

