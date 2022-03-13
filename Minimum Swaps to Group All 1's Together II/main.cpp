#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int noOfOnes = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) noOfOnes++;
            nums.push_back(nums[i]);
        }
        int x = noOfOnes;
        int maxOnes = INT_MIN;

        if (noOfOnes == 0) return 0;

        vector<int> preCompute(2 * n);
        if (nums[0] == 1) preCompute[0] = 1;
        for (int i = 1; i < 2 * n; i++) {
            preCompute[i] = preCompute[i - 1] + nums[i];
        }

        for (int i = x - 1; i < 2 * n; i++) {
            if (i == (x - 1)) noOfOnes = preCompute[i];
            else noOfOnes = preCompute[i] - preCompute[i - x];

            if (maxOnes < noOfOnes) maxOnes = noOfOnes;
        }

        int noOfZeroes = x - maxOnes;
        return noOfZeroes;
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

