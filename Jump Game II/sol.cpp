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
const int inf = 0x3f3f3f3f;
struct SegTree {

	int Min[MAXN << 2];

	int lson(int rt) {return rt << 1; }
	int rson(int rt) {return rt << 1 | 1; }

	void pushUp(int rt) {
		Min[rt] = min(Min[lson(rt)], Min[rson(rt)]);
	}

	void build(int l, int r, int rt) {
		if (l == r) {
			Min[rt] = inf;
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
	}

	int query(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return Min[rt];
		}
		int mid = (l + r) >> 1;
		int ret = inf;
		if (L <= mid) ret = min(ret, query(L, R, l, mid, lson(rt)));
		if (R > mid) ret = min(ret, query(L, R, mid + 1, r, rson(rt)));
		return ret;
	}

	void update(int pos, int c, int l, int r, int rt) {
		if (l == r) {
			Min[rt] = c;
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) update(pos, c, l, mid, lson(rt));
		else update(pos, c, mid + 1, r, rson(rt));
		pushUp(rt);
	}
}tree;

class Solution {
public:
	int jump(int A[], int n) {
		if (n == 1) return 0;
		tree.build(0, n - 1, 1);	
		tree.update(n - 1, 0, 0, n - 1, 1);
		for (int i = n - 2; i >= 0; i--) {
			int l = i + 1, r = min(n - 1, i + A[i]);
			int step = tree.query(l, r, 0, n - 1, 1);
			tree.update(i, step + 1, 0, n - 1, 1);
		}
		return tree.query(0, 0, 0, n - 1, 1);
	}
};

int main() {
	Solution s;
	int A[] = {3, 1, 1, 1, 1};
	//int A[] = {2, 3, 1, 1, 4};
	int res = s.jump(A, 5);
	cout << res << endl;
	return 0;
}

