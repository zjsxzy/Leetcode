#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// index from 0
struct Fenwick{
    using T = int;
    vector<T> tree;
    int n;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, T val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    T get(int r) {
        T ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    T get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
        vector<int> nums2 = nums;
        for (auto& x: nums2) {
            x = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
        }
        int m = vec.size();

        vector<int> arr1, arr2;
        Fenwick tree1(m + 1), tree2(m + 1);
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i], v = nums2[i];
            if (arr1.empty()) {
                arr1.push_back(x);
                tree1.upd(v, 1);
            } else if (arr2.empty()) {
                arr2.push_back(x);
                tree2.upd(v, 1);
            } else {
                int count1 = arr1.size() - tree1.get(v);
                int count2 = arr2.size() - tree2.get(v);
                if (count1 > count2) {
                    arr1.push_back(x);
                    tree1.upd(v, 1);
                } else if (count1 < count2) {
                    arr2.push_back(x);
                    tree2.upd(v, 1);
                } else if (arr1.size() < arr2.size()) {
                    arr1.push_back(x);
                    tree1.upd(v, 1);
                } else if (arr1.size() > arr2.size()) {
                    arr2.push_back(x);
                    tree2.upd(v, 1);
                } else {
                    arr1.push_back(x);
                    tree1.upd(v, 1);
                }
            }
        }
        vector<int> ans = arr1;
        for (auto x: arr2) ans.push_back(x);
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

