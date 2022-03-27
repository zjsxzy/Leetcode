#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        set<int> t;
        for (auto x: nums1) {
            bool flag = false;
            for (auto y: nums2) {
                if (x == y) {
                    flag = true;
                    break;
                }
            }
            if (!flag) t.insert(x);
        }
        vector<int> add;
        for (auto x: t) add.push_back(x);
        res.push_back(add);
        t.clear();
        add.clear();
        for (auto x: nums2) {
            bool flag = false;
            for (auto y: nums1) {
                if (x == y) {
                    flag = true;
                    break;
                }
            }
            if (!flag) t.insert(x);
        }
        for (auto x: t) add.push_back(x);
        res.push_back(add);
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

