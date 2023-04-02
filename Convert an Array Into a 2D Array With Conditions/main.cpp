#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(205);
        for (auto x: nums) {
            cnt[x]++;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            bool flag = true;
            vector<int> t;
            for (int x = 0; x < 205; x++) {
                if (cnt[x]) {
                    flag = false;
                    t.push_back(x);
                    cnt[x]--;
                }
            }
            if (!flag) ans.push_back(t);
        }
        return ans;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

