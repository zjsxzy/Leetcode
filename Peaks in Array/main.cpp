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
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        Fenwick tree(n + 1);
        vector<int> a(n + 1), b(n + 1);
        for (int i = 0; i < n; i++) {
            a[i + 1] = nums[i];
        }
        for (int i = 1; i <= n; i++) {
            if (i > 1 && i < n) {
                b[i] = (a[i] > a[i - 1]) & (a[i] > a[i + 1]);
                tree.upd(i, b[i]);
            }
        }
        vector<int> ans;
        for (auto q: queries) {
            int op = q[0];
            if (op == 1) {
                int l = q[1] + 1, r = q[2] + 1;
                ans.push_back(tree.get(l + 1, r - 1));
            } else {
                int index = q[1] + 1, val = q[2];
                for (int i = max(1, index - 1); i <= min(n, index + 1); i++) {
                    if (b[i] == 1) {
                        b[i] = 0;
                        tree.upd(i, -1);
                    }
                }
                a[index] = val;
                for (int i = max(1, index - 1); i <= min(n, index + 1); i++) {
                    if (i > 1 && i < n) {
                        b[i] = (a[i] > a[i - 1]) & (a[i] > a[i + 1]);
                        tree.upd(i, b[i]);
                    }
                }
            }
        }
        return ans;
    }
};

void solve() {
}

int main() {
#ifndef ONLINE_JUDGE
    (void)!freopen("in.txt", "r", stdin);
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

