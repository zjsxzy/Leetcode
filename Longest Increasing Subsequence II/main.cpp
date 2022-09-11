#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 100005;
const int inf = 1e9;
int a[MAXN];
struct SegTree {
	int mx[MAXN << 2];
	int lson(int rt) {return rt << 1;}
	int rson(int rt) {return rt << 1 | 1;}
	void pushUp(int rt) {
		mx[rt] = max(mx[lson(rt)], mx[rson(rt)]);
	}
	void build(int l, int r, int rt) {
		if (l == r) {
			mx[rt] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}
	int query(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return mx[rt];
		}
		int mid = (l + r) >> 1;
		int res = -inf;
		if (L <= mid) res = max(res, query(L, R, l, mid, lson(rt)));
		if (mid < R) res = max(res, query(L, R, mid + 1, r, rson(rt)));
		return res;
	}
    void update(int p, int val, int l, int r, int rt) {
        if (l == r) {
            mx[rt] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (p <= mid) update(p, val, l, mid, lson(rt));
        else update(p, val, mid + 1, r, rson(rt));
        pushUp(rt);
    }
}tree;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size(), m = 0;
        for (auto x: nums) m = max(m, x);
        for (int i = 1; i <= m; i++) a[i] = 0;
        tree.build(1, m, 1);
        int res = 1;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            int t = 0;
            if (x > 1) t = tree.query(max(1, x - k), x - 1, 1, m, 1); // 严格递增
            res = max(res, t + 1);
            tree.update(x, t + 1, 1, m, 1);
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

