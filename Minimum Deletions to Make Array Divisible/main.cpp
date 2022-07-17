#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), m = numsDivide.size();
        int g = numsDivide[0];
        for (int i = 1; i < m; i++) {
            g = gcd(g, numsDivide[i]);
        }
        for (int i = 0; i < n; i++) {
            if (g % nums[i] == 0) return i;
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
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

