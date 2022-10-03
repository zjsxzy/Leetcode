#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// index from 0
struct Fenwick{
    vector<int> tree;
    int n;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, int val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    int get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        int m = 1e5;
        Fenwick tree(2 * m);
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += tree.get(m + nums1[i] - nums2[i] + diff);
            tree.upd(m + nums1[i] - nums2[i], 1);
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

