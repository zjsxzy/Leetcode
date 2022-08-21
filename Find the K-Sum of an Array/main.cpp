#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long sum = 0;
        for (auto& x: nums) {
            if (x >= 0) sum += x;
            else x = -x;
        }
        sort(nums.begin(), nums.end());
        priority_queue<pair<long long, int>> pq;
        pq.push({sum, 0});
        k--;
        while (k--) {
            auto [s, i] = pq.top(); pq.pop();
            if (i < nums.size()) {
                pq.push({s - nums[i], i + 1});
                if (i) pq.push({s - nums[i] + nums[i - 1], i + 1});
            }
        }
        return pq.top().first;
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

