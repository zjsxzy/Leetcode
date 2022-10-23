#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<vector<int>> a(2), b(2);
        for (int i = 0; i < n; i++) {
            a[nums[i] & 1].push_back(nums[i]);
            b[target[i] & 1].push_back(target[i]);
        }
        long long sum = 0;
        for (int i = 0; i < 2; i++) {
            sort(a[i].begin(), a[i].end());
            sort(b[i].begin(), b[i].end());
            int m = a[i].size();
            for (int j = 0; j < m; j++) {
                sum += abs(a[i][j] - b[i][j]);
            }
        }
        return sum / 4;
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

