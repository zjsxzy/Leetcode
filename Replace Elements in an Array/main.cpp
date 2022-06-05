#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n = nums.size();
        map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }
        for (auto& op: operations) {
            pos[op[1]] = pos[op[0]];
            nums[pos[op[0]]] = op[1];
        }
        return nums;
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

