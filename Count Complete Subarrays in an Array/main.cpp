#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> vst(2005);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (!vst[nums[i]]) sum++;
            vst[nums[i]] = 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            vst.assign(2005, 0);
            int t = 0;
            for (int j = i; j < n; j++) {
                if (!vst[nums[j]]) t++;
                res += (t == sum);
                vst[nums[j]] = 1;
            }
        }
        return res;
    }
};

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
       solve();
    }
    return 0;
}

