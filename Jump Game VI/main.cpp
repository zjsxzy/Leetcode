#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
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
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            a[i + 1] = nums[i];
        }
        tree.build(1, n, 1);
        vector<int> dp(n + 1);
        dp[1] = a[1];
        for (int i = 2; i <= n; i++) {
            int l = max(1, i - k), r = i - 1;
            int t = tree.query(l, r, 1, n, 1);
            dp[i] = t + a[i];
            tree.update(i, dp[i], 1, n, 1);
        }
        return dp[n];
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

