#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] > k) arr[i] = 1;
            else if (nums[i] < k) arr[i] = -1;
            else arr[i] = 0;
        }

        vector<int> pref(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + arr[i];
        }

        int res = 0;
        map<int, int> mp;
        vector<int> vec;
        vec.push_back(0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                while (vec.size()) {
                    mp[vec.back()]++;
                    vec.pop_back();
                }
            } else {
                vec.push_back(pref[i]);
            }
            res += mp[pref[i]] + mp[pref[i] - 1];
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

