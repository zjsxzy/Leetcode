#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({nums[i], cost[i]});
        }
        sort(vec.begin(), vec.end());

        map<int, long long> mp1, mp2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                mp1[vec[i].first] = mp1[vec[i - 1].first] + sum * (vec[i].first - vec[i - 1].first);
            } else {
                mp1[vec[i].first] = 0;
            }
            sum += vec[i].second;

        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                mp2[vec[i].first] = 0;
            } else {
                mp2[vec[i].first] = mp2[vec[i + 1].first] + sum * (vec[i + 1].first - vec[i].first);
            }
            sum += vec[i].second;
        }

        long long res = 1ll << 60;
        for (auto [k, v]: mp1) {
            res = min(res, v + mp2[k]);
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
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

