#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i % 10 == nums[i]) {
                return i;
            }
        }
        return -1;
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

