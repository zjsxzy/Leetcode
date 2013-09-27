#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 50005;
struct SegTree {

	int sum[MAXN << 2], flag[MAXN << 2];

	int lson(int rt) {return rt << 1; }
	int rson(int rt) {return rt << 1 | 1; }

	void pushUp(int rt) {
		sum[rt] = sum[lson(rt)] + sum[rson(rt)];
	}

	void pushDown(int rt, int m) {
		if (flag[rt] != -1) {
			flag[lson(rt)] = flag[rt];
			flag[rson(rt)] = flag[rt];
			sum[lson(rt)] = (m - (m >> 1)) * flag[rt];
			sum[rson(rt)] = (m >> 1) * flag[rt];
			flag[rt] = -1;
		}
	}

	void build(int l, int r, int rt) {
		flag[rt] = -1;
		if (l == r) {
			sum[rt] = 0;
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}

	int query(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return sum[rt];
		}
		pushDown(rt, r - l + 1);
		int mid = (l + r) >> 1;
		int ret = 0;
		if (L <= mid) ret += query(L, R, l, mid, lson(rt));
		if (R > mid) ret += query(L, R, mid + 1, r, rson(rt));
		return ret;
	}

	void update(int L, int R, int c, int l, int r, int rt) {
		if (L <= l && r <= R) {
			flag[rt] = c;
			sum[rt] = c * (r - l + 1);
			return;
		}
		pushDown(rt, r - l + 1);
		int mid = (l + r) >> 1;
		if (L <= mid) update(L, R, c, l, mid, lson(rt));
		if (R > mid) update(L, R, c, mid + 1, r, rson(rt));
		pushUp(rt);
	}
}tree;

class Solution {
public:
	int jump(int A[], int n) {
		tree.build(0, n - 1, 1);	
		int limit = 0;
		for (int i = 0; i < n - 1; i++) {
			if (i + A[i] > limit) {
				int cur = tree.query(i, i, 0, n - 1, 1);
				if (i + A[i] >= n - 1) {
					return cur + 1;
				}
				tree.update(limit + 1, min(n - 1, i + A[i]), cur + 1, 0, n - 1, 1);
				limit = i + A[i];
			}
		}
		return tree.query(n - 1, n - 1, 0, n - 1, 1);
	}
};

int main() {
	Solution s;
	int A[] = {3, 1, 1, 1, 1};
	int res = s.jump(A, 5);
	cout << res << endl;
	return 0;
}
