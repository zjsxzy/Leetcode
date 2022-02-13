#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        map<int, int> odd, even;
        int o = 0, e = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                odd[nums[i]]++;
                o++;
            } else {
                even[nums[i]]++;
                e++;
            }
        }
        vector<pair<int, int>> on, en;
        for (auto& [k, v]: odd) {
            on.push_back({-v, k});
        }
        for (auto& [k, v]: even) {
            en.push_back({-v, k});
        }
        sort(on.begin(), on.end());
        sort(en.begin(), en.end());
        int res = INT_MAX;
        for (auto p: on) {
            int t = o + p.first;
            int i;
            for (i = 0; i < en.size(); i++) {
                if (en[i].second != p.second) {
                    break;
                }
            }
            if (i == en.size()) res = min(res, t + e);
            else res = min(res, t + (e + en[i].first));
        }
        for (auto p: en) {
            int t = e + p.first;
            int i;
            for (i = 0; i < on.size(); i++) {
                if (on[i].second != p.second) {
                    break;
                }
            }
            if (i == on.size()) res = min(res, t + o);
            else res = min(res, t + (o + on[i].first));
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

